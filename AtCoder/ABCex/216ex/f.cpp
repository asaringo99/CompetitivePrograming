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

int n ;
P A[5050] ;
ll dp[5050][5050] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i].first ;
    rep(i,n) cin >> A[i].second ;
    sort(A,A+n) ;
    ll res = 0 ;
    dp[0][0] = 1 ;
    rep(i,n){
        auto [a,b] = A[i] ;
        rep(j,5001){
            (dp[i+1][j] += dp[i][j])%= mod ;
            if(j + b <= 5000) (dp[i+1][j+b] += dp[i][j]) %= mod ;
            if(j + b <= a) (res += dp[i+1][j+b]) %= mod ;
        }
    }
    cout << res << endl ;
}