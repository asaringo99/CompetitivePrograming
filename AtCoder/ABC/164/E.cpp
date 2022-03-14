#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge
{
    int to ;
    ll cost , pay ;
};

int n , m , s ;
ll C[100] , D[100] , dp[100][3000] ;
vector<edge> G[100] ;

void dijkstra(){
    rep(i,n) rep(j,3000) dp[i][j] = 1e16 ;
    s = min(s,2999) ;
    dp[0][s] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,s}) ;
    while(!que.empty()){
        TP tp = que.top() ; que.pop() ;
        ll v , pay , tim ;
        tie(tim,v,pay) = tp ;
        if(dp[v][pay] < tim) continue ;
        if(pay + C[v] < 3000 && dp[v][pay+C[v]] > dp[v][pay] + D[v]){
            dp[v][pay+C[v]] = tim + D[v] ;
            que.push({tim+D[v],v,pay+C[v]}) ;
        }
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(pay - e.pay < 0) continue ;
            if(dp[e.to][pay-e.pay] > dp[v][pay] + e.cost){
                dp[e.to][pay-e.pay] = dp[v][pay] + e.cost ;
                que.push({dp[e.to][pay-e.pay],e.to,pay-e.pay}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m >> s ;
    rep(i,m){
        int u , v , a , b ;
        cin >> u >> v >> b >> a ;
        u-- ;
        v-- ;
        G[u].push_back(edge{v,a,b}) ;
        G[v].push_back(edge{u,a,b}) ;
    }
    rep(i,n) cin >> C[i] >> D[i] ;
    dijkstra() ;
    rrep(i,1,n){
        ll res = LLONG_MAX ;
        rep(j,3000) res = min(res,dp[i][j]) ;
        cout << res << endl ;
    }
}