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

int n , m ;
int dp[101010] ;
vector<int> G[101010] ;

int dfs(int v , int prev){
    if(dp[v] != -1) return dp[v] ;
    int res = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue;
        chmax(res,dfs(u,v)+1) ;
    }
    return dp[v] = res ;
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        int x , y ;
        cin >> x >> y ;
        x-- ; y-- ;
        G[x].push_back(y) ;
    }
    rep(i,n) dp[i] = -1 ;
    int res = 0 ;
    rep(i,n) chmax(res,dfs(i,-1)) ;
    cout << res << endl ;
}