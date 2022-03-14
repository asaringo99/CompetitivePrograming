#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll n ;
ll C[202020] ;

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
    cin >> n ;
    rep(i,n) cin >> C[i] ;
    sort(C,C+n) ;
    ll res = 0 ;
    rep(i,n) (res += C[i] * (n-i+1) % mod) %= mod ;
    (res *= powmod(2,n-1) * powmod(2,n-1) % mod) %= mod ;
    cout << res << endl ;
}