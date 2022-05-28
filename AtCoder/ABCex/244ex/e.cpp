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

const int mod = 998244353 ;

int n , m , k , s , t , x ;
vector<int> G[2020] ;

ll dp[2020][2020][2] ;

int main(){
    fast_input_output
    cin >> n >> m >> k >> s >> t >> x ;
    s-- ; t-- ; x-- ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dp[0][s][0] = 1 ;
    rep(i,k+1) rep(v,n) {
        for(int u : G[v]){
            if(u == x) {
                (dp[i+1][u][1] += dp[i][v][0]) %= mod ;
                (dp[i+1][u][0] += dp[i][v][1]) %= mod ;
            }
            else {
                (dp[i+1][u][0] += dp[i][v][0]) %= mod ;
                (dp[i+1][u][1] += dp[i][v][1]) %= mod ;
            }
        }
    }
    cout << dp[k][t][0] << endl ;
}