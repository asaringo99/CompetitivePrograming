#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define INF (ll)1e16
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n , m ;
vector<int> G[MAX_N] ;
ll A[MAX_N] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
    }
    ll dp[n] ;
    fill(dp,dp+n,INF) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < G[i].size() ; j++){
            int u = G[i][j] ;
            dp[u] = min(dp[u],min(dp[i],A[i])) ;
        }
    }
    ll ans = -INF ;
    rep(i,n){
        ans = max(ans,A[i] - dp[i]) ;
    }
    cout << ans << endl ;
}