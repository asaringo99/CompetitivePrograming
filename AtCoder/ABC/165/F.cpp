#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[202020] ;
vector<int> G[202020] ;
ll dp[202020] ;
int res[202020] ;

void dfs(int v , int prev){
    int t = lower_bound(dp,dp+n,A[v]) - dp ;
    ll val = dp[t] ;
    dp[t] = A[v] ;
    int id = lower_bound(dp,dp+n,1e15) - dp ;
    res[v] = id ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
    }
    dp[t] = val ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ;
        v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    fill(dp,dp+n,1e16) ;
    dfs(0,-1) ;
    rep(i,n) cout << res[i] << endl ;
}