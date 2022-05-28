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
ld p[3030] ;
ld dp[3030][3030] ;

int main(){
    fast_input_output
    cin >> n ;
    dp[0][0] = 1 ;
    rep(i,n) cin >> p[i] ;
    rep(i,n){
        rep(j,i+1){
            dp[i+1][j] += dp[i][j] * (1 - p[i]) ;
            dp[i+1][j+1] += dp[i][j] * p[i] ;
        }
    }
    ld res = 0 ;
    rrep(i,n/2+1,n+1) res += dp[n][i] ;
    cout << fixed << setprecision(25) << res << endl ;
}