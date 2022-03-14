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

const int mod = 1000000007 ;

int n ;
ll A[303030] ;
ll B[101] ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        rep(j,60) if(a >> j & 1) B[j]++ ;
    }
    ll res = 0 ;
    ll sum = 1 ;
    rep(i,60){
        res += sum * B[i] % mod * (n - B[i]) % mod ;
        res %= mod ;
        sum *= 2 ;
        sum %= mod ;
    }
    cout << res << endl ;
}