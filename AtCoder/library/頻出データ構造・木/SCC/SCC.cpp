#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int MAX_N = 202020 ;

struct SCC{
    int n ;
    int new_node ;

    // G       : 既存の有向辺についての情報
    // F       : 既存の有向辺（逆辺）についての情報
    // H       : 新たなグラフ（有向辺）の辺についての情報
    // used    : dfsで使ったか
    // Reused  : Redfsで使ったか
    // convert : 新たなノードに変換する
    // volume  : 新たなノードに集約されたノード個数
    // go      : v -> u に行ったことがあるか

    vector<int> G[MAX_N] , F[MAX_N] ;
    vector<int> order , H[MAX_N] ;
    bool used[MAX_N] , Reused[MAX_N] ;
    int convert[MAX_N] ;
    int volume[MAX_N] ;
    map<P,bool> go ;

    // n_ : グラフのノード数
    SCC(int n_){
        memset(used,0,sizeof(used)) ;
        memset(Reused,0,sizeof(Reused)) ;
        n = n_ ;
        new_node = 0 ;
    }

    void dfs(int v){
        used[v] = true ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(used[u]) continue ;
            dfs(u) ;
        }
        order.push_back(v) ;
    }

    void Redfs(int s , int v){
        Reused[v] = true ;
        convert[v] = s ;
        volume[s]++ ;
        for(int i = 0 ; i < F[v].size() ; i++){
            int u = F[v][i] ;
            if(Reused[u]) continue ;
            Redfs(s,u) ;
        }
    }

    void build(){
        // 処理1 : 1度目のdfs
        for(int i = 0 ; i < n ; i++) if(!used[i]) dfs(i) ;
        // 処理2 : 2度目のdfs
        for(int i = 0 ; i < n ; i++) {
            int v = order[n-1-i] ;
            if(Reused[v]) continue ;
            Redfs(new_node,v) ;
            new_node++ ;
        }
        // 処理3 : 新しいグラフを作成する
        for(int i = 0 ; i < n ; i++){
            for(int u : G[i]){
                int from = convert[i] , to = convert[u] ;
                if(from == to) continue ;
                if(go[P(from,to)]) continue ;
                go[P(from,to)] = true ;
                H[from].push_back(to) ;
            }
        }
    }

    inline void add_edge(int v , int u) {
        G[v].push_back(u) ;
        F[u].push_back(v) ;
    }
    int root(int v) {return convert[v] ; }
    int new_gragh_size(){ return new_node ; }
    int integrated_node_size(int v){ return volume[v] ; }
    inline vector<int>& operator [] (int v) { return H[v] ; } 
} ;

int n , m ;

int main(){
    cin >> n >> m ;
    SCC scc(n) ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        scc.add_edge(a,b) ;
    }
}