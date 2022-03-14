#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

string T ;
ll S[202020] ;
int n ;

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
    cin >> T ;
    n = T.size() ;
    rep(i,n) S[i+1] = S[i] + (T[i] - '0') ;
    ll res = 0 ;
    rep(i,n){
        if(i > 0) (res += S[i] * powmod(10,n-1-i) % mod * powmod(2,i-1) % mod) %= mod ;
        (res += (T[i]-'0') * powmod(10,n-1-i) % mod * powmod(2,i) % mod) %= mod ;
    }
    cout << res << endl ;
}