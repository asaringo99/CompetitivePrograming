#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , q ;
const int MAX_N = 100007 , MAX_K = 20 ;

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
    //距離を求める
    int dist_u_to_v(int u , int v){
        int node = query(u,v) ;
        return dist[u] + dist[v] - 2*dist[node] ;
    }
};

int main(){
    cin >> n ;
    for(int i = 0 ; i < n - 1 ; i++){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    LCA tree(n) ;
    cin >> q ;
    for(int i = 0 ; i < q ; i++){
        int u , v ;
        cin >> u >> v ;
        u-- ;
        v-- ;
        cout << tree.dist_u_to_v(u,v) + 1 << endl ;
    }
}