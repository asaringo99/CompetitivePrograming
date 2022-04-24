#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n ;
ll C[202020] ;

ll powmod(ll x , ll n){
    if(n < 0) return 0 ;
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        n >>= 1 ;
        (x *= x) %= mod ;
    }
    return res ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> C[i] ;
    sort(C,C+n) ;
    ll res = 0 ;
    rep(i,n){
        ll val = (n-1-i) * powmod(2,n-2-i) % mod + powmod(2,n-1-i) ;
        res += powmod(2,n-1+i) * 2 % mod * val % mod * C[i] % mod ;
        res %= mod ;
    }
    cout << res << endl ;
}