#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge
{
    int to ;
    ll cost ;
};


int n , m ;
ll d[500] ;
int prevv[500] ;
bool useedge[500][500] ;

vector<edge> G[500] ;

void bfs(int goal){
    rep(i,n) d[i] = INT_MAX ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        // cout << v << " " << d[v][0] << " " << d[v][1] << endl ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(useedge[v][e.to]) continue ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                prevv[e.to] = v ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int u , v , l ;
        cin >> u >> v >> l ;
        u-- ;
        v-- ;
        G[u].push_back({v,l}) ;
        G[v].push_back({u,l}) ;
    }
    ll ans = INT_MAX ;
    rrep(i,1,n){
        memset(useedge,0,sizeof(useedge)) ;
        bfs(i) ;
        ll val = d[i] ;
        for(int node = i ; node != 0 ; node = prevv[node]){
            useedge[prevv[node]][node] = true ;
        }
        bfs(i) ;
        val += d[i] ;
        ans = min(ans,val) ;
    }
    if(ans == INT_MAX) ans = -1 ;
    cout << ans << endl ;
}