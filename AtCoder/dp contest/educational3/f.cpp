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

string S , T ;
int n , m ;

int dp[3030][3030] ;
P pre[3030][3030] ;

int main(){
    fast_input_output
    cin >> S >> T ;
    n = S.size() ;
    m = T.size() ;
    rrep(i,1,n+1) rrep(j,1,m+1){
        if(S[i-1] == T[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1 ;
            pre[i][j] = P(i-1,j-1) ;
        }
        if(dp[i][j] < dp[i-1][j]){
            dp[i][j] = dp[i-1][j] ;
            pre[i][j] = P(i-1,j) ;
        }
        if(dp[i][j] < dp[i][j-1]){
            dp[i][j] = dp[i][j-1] ;
            pre[i][j] = P(i,j-1) ;
        }
    }
    string res = "" ;
    while(n != 0 && m != 0){
        P p = pre[n][m] ;
        if(dp[p.first][p.second] + 1 == dp[n][m]) res += S[n-1] ;
        n = p.first ;
        m = p.second ;
    }
    for(int i = res.size() - 1 ; i >= 0 ; i--) cout << res[i] ; cout << endl ;

}