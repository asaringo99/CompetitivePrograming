#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 2019 ;
string S ;
map<ll,ll> mp ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> S ;
    int n = S.size() ;
    ll sum = 0 , res = 0 ; mp[0]++ ;
    rep(i,n){
        (sum += (ll)(S[n-1-i] - '0') * powmod(10,i) % mod) %= mod ;
        res += mp[sum] ;
        mp[sum]++ ;
    }
    cout << res << endl ;
}