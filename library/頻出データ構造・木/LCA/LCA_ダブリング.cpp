#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , q ;
const int MAX_N = 101010 ;

vector<int> G[MAX_N] ;
struct LCA{
    int n ;
    vector<int> dist ;
    vector<vector<int>> parent ;
    LCA(int n_){
        n = n_ ;
        dist.resize(n,-1) ;
        parent.resize(n,vector<int>(30,-1)) ;
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

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int k ;
        cin >> k ;
        for(int j = 0 ; j < k ; j++){
            int v ;
            cin >> v ;
            G[i].push_back(v) ;
            G[v].push_back(i) ;
        }
    }
    LCA tree(n) ;
    cin >> q ;
    for(int i = 0 ; i < q ; i++){
        int u , v ;
        cin >> u >> v ;
        cout << tree.query(u,v) << endl ;
    }
}