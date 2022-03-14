#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
ll A[10007] ;
int prime[1010101] ;
unordered_map<int,ll> mp ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void ertstns(){
    memset(prime,-1,sizeof(prime)) ;
    prime[0] = prime[1] = 1 ;
    for(int i = 2 ; i < 1010101 ; i++){
        if(prime[i] == -1){
            for(int j = i ; j < 1010101 ; j += i) prime[j] = i ;
        }
    }
}

int main(){
    ertstns() ;
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        A[i] = a ;
        map<int,ll> rem ;
        while(a != 1){
            rem[prime[a]]++ ;
            a /= prime[a] ;
        }
        for(auto it : rem) mp[it.first] = max(mp[it.first],it.second) ;
    }
    ll lcm = 1 ;
    for(auto it : mp) (lcm *= powmod(it.first,it.second)) %= mod ;
    
    ll res = 0 ;
    rep(i,n) (res += lcm * powmod(A[i],mod-2) % mod) %= mod;
    cout << res << endl ;
}