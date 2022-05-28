#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n ;
ll A[303030] ;
ll dp[303030][2] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n+1) rep(j,2) dp[i][j] = 1e16 ;
    dp[0][0] = 0 ;
    ll res = 1e18 ;
    rep(i,n){
        chmin(dp[i+1][1], dp[i][0] + A[i]) ;
        chmin(dp[i+1][1], dp[i][1] + A[i]) ;
        chmin(dp[i+1][0], dp[i][1]) ;
    }
    chmin(res,dp[n][0]) ;
    chmin(res,dp[n][1]) ;
    rep(i,n+1) rep(j,2) dp[i][j] = 1e16 ;
    dp[0][1] = 0 ;
    rep(i,n){
        chmin(dp[i+1][1], dp[i][0] + A[i]) ;
        chmin(dp[i+1][1], dp[i][1] + A[i]) ;
        chmin(dp[i+1][0], dp[i][1]) ;
    }
    chmin(res,dp[n][1]) ;
    cout << res << endl ;
}