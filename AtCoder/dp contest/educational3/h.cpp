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

const int mod = 1000000007 ;

int H , W ;
char C[5050][5050] ;
ll dp[5050][5050] ;

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> C[i][j] ;
    dp[0][0] = 1 ;
    rep(i,H) rep(j,W){
        if(C[i][j] == '#') continue;
        (dp[i+1][j] += dp[i][j]) %= mod ;
        (dp[i][j+1] += dp[i][j]) %= mod ;
    }
    cout << dp[H-1][W-1] << endl ;
}