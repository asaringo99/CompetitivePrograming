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

int n , w ;
ll W[101] , V[101] ;
ll dp[101][101010] ;

int main(){
    fast_input_output
    cin >> n >> w ;
    rep(i,n) cin >> W[i] >> V[i] ;
    rep(i,n+1) rep(j,100001) dp[i][j] = w + 1 ;
    dp[0][0] = 0 ;
    rep(i,n) rep(j,100001){
        chmin(dp[i+1][j],dp[i][j]) ;
        chmin(dp[i+1][j+V[i]],dp[i][j]+W[i]) ;
    }
    ll res = 0 ;
    rep(i,100001) if(dp[n][i] <= w) res = i ;
    cout << res << endl ;
}