#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,ll,ll,bool> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 101010 , MAX_K = 20 ;

struct edge{
    int to , color ;
    ll cost ;
} ;

vector<int> G[MAX_N] ;
int dist[MAX_N] ;
int parent[MAX_N][MAX_K] ;

vector<edge> F[101010] ;
vector<TP> query[101010] ;
ll res[101010] ;
ll cnt[101010] ;
ll len[101010] ;
ll tot[101010] ;

struct LCA{
    int n ;
    LCA(int n_){
        n = n_ ;
        memset(dist,-1,sizeof(dist)) ;
        memset(parent,-1,sizeof(parent)) ;
        dfs(0,-1,0) ;
        for(int i = 0 ; i < 19 ; i++){
            for(int node = 0 ; node < n ; node++){
                if(parent[node][i] >= 0) parent[node][i+1] = parent[parent[node][i]][i] ;
            }
        }
    }
    //深さ優先探索
    void dfs(int v , int prev , int d){
        dist[v] = d ;
        parent[v][0] = prev ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(dist[u] == -1){
                dfs(u,v,d+1) ;
            }
        }
    }
    //LCAを求める
    int query(int u , int v){
        if(dist[u] < dist[v]) swap(u,v) ;
        for(int i = 0 ; i < 20 ; i++){
            if((dist[v] - dist[u]) >> i & 1) u = parent[u][i] ;
        }
        if(u == v) return u ;
        for(int i = 19 ; i >= 0 ; i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i] ;
                v = parent[v][i] ;
            }
        }
        return parent[u][0] ;
    }
    //距離を求める
    int dist_u_to_v(int u , int v){
        int node = query(u,v) ;
        return dist[u] + dist[v] - 2*dist[node] ;
    }
    //u-vパス上に頂点nodeが存在するか
    bool node_is_on_path(int u , int v , int node){
        return dist_u_to_v(u,v) == dist_u_to_v(u,node) + dist_u_to_v(node,v) ;
    }
};

void DFS(int v , int prev){
    for(TP tp : query[v]){
        ll id , x , y ;
        bool ok ;
        tie(id,x,y,ok) = tp ;
        if(ok) {
            res[id] -= 2 * tot[v] ;
            res[id] += 2 * len[x];
            res[id] -= 2 * cnt[x] * y ;
        }
        else{
            res[id] += tot[v] ;
            res[id] -= len[x];
            res[id] += cnt[x] * y ;
        }
    }
    for(int i = 0 ; i < F[v].size() ; i++){
        edge e = F[v][i] ;
        if(e.to == prev) continue ;
        len[e.color] += e.cost ;
        cnt[e.color] += 1 ;
        tot[e.to] = tot[v] + e.cost ;
        DFS(e.to,v) ;
        len[e.color] -= e.cost ;
        cnt[e.color] -= 1 ;
    }
}

int n , q ;

int main(){
    cin >> n >> q ;

    rep(i,n-1){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
        F[a].push_back(edge{b,c,d}) ;
        F[b].push_back(edge{a,c,d}) ;
    }

    LCA lca(n) ;
    rep(i,q){
        int x , y , u , v ;
        cin >> x >> y >> u >> v ;
        u-- ; v-- ;
        query[u].push_back({i,x,y,false}) ;
        query[v].push_back({i,x,y,false}) ;
        query[lca.query(u,v)].push_back({i,x,y,true}) ;
    }
    DFS(0,-1) ;
    rep(i,q){
        cout << res[i] << endl ;
    }
}