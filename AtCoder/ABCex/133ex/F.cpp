#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , q ;
const int MAX_N = 200007 , MAX_K = 20 ;

vector<int> G[MAX_N] ;
int dist[MAX_N] ;
int parent[MAX_N][MAX_K] ;

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
};

struct edge
{
    int to , color ;
    ll cost ;
};

struct que
{
    int num , color , delta ;
    ll clen ;
};

vector<edge> E[MAX_N] ;
vector<que> Q[MAX_N] ; 
ll collen[MAX_N] ;
int colsum[MAX_N] ;
ll ans[MAX_N] ;
bool used[MAX_N] ;

void dfs(int v , int d){
    used[v] = true ;
    for(int i = 0 ; i < Q[v].size() ; i++){
        que query = Q[v][i] ;
        ll num = query.num , color = query.color , clen = query.clen , delta = query.delta ;
        ans[num] += (d - collen[color] + colsum[color] * clen) * delta ;
    }
    for(int i = 0 ; i < E[v].size() ; i++){
        edge e = E[v][i] ;
        if(!used[e.to]){
            collen[e.color] += e.cost ;
            colsum[e.color]++ ;
            dfs(e.to,d+e.cost) ;
            collen[e.color] -= e.cost ;
            colsum[e.color]-- ;
        }
    }
}

int main(){
    cin >> n >> q ;
    memset(dist,0,sizeof(dist)) ;
    rep(i,n-1){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
        E[a].push_back(edge{b,c,d}) ;
        E[b].push_back(edge{a,c,d}) ;
    }
    LCA tree(n) ;
    memset(collen,0,sizeof(collen)) ;
    memset(colsum,0,sizeof(colsum)) ;
    memset(ans,0,sizeof(ans)) ;
    memset(used,0,sizeof(used)) ;
    for(int i = 0 ; i < q ; i++){
        int x , y , u , v ;
        cin >> x >> y >> u >> v ;
        u-- ;
        v-- ;
        Q[u].push_back(que{i,x,1,y}) ;
        Q[v].push_back(que{i,x,1,y}) ;
        Q[tree.query(u,v)].push_back(que{i,x,-2,y}) ;
    }
    dfs(0,0) ;
    for(int i = 0 ; i < q ; i++) cout << ans[i] << endl ;
}