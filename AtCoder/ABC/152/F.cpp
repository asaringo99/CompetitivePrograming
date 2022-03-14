#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
const int MAX_N = 100007 , MAX_K = 20 ;

vector<int> G[MAX_N] ;
int dist[MAX_N] ;
int parent[MAX_N][MAX_K] ;
int nov[MAX_N] ;

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
        nov[v] = prev ;
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

vector<int> get_path(int s , int t){
    vector<int> path ;
    for(int node = t ; node != s ; node = nov[node]) {
        path.push_back(node) ;
    }
    reverse(path.begin(),path.end()) ;
    return path ;
}

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    LCA lca(n) ;
    vector<ll> vec ;
    cin >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ;
        v-- ;
        int node = lca.query(u,v) ;
        cout << lca.query(0,1) << endl ;
        vector<int> path1 = get_path(node,u) ;
        vector<int> path2 = get_path(node,v) ;
        ll val = 0 ;
        for(ll tmp : path1) val += powll(2,tmp) ;
        for(ll tmp : path2) val += powll(2,tmp) ;
        vec.push_back(val) ;
    }
    ll res = 0 ;
    rrep(i,1,1<<m){
        ll val = 0 ;
        int count = 0 ;
        rep(j,m) if(i >> j & 1){
            val |= vec[j] ;
            count++ ;
        }
        int sum = 0 ;
        rep(j,n) if(val >> j & 1) sum++ ;
        if(count % 2 == 1) res += powll(2,n-1-sum) ;
        if(count % 2 == 0) res -= powll(2,n-1-sum) ;
    }
    ll ans = powll(2,n-1) - res ;
    cout << ans << endl ;
}