#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct SCC{
    private :
        int n ;
        int new_node ;

        // G       : 既存の有向辺についての情報
        // F       : 既存の有向辺（逆辺）についての情報
        // H       : 新たなグラフ（有向辺）の辺についての情報
        // used    : dfsで使ったか
        // reused  : Redfsで使ったか
        // convert : 新たなノードに変換する
        // volume  : 新たなノードに集約されたノード個数
        // go      : v -> u に行ったことがあるか

        vector<vector<int>> G , F ;
        vector<int> order ;
        vector<bool> used , reused ;
        vector<int> convert ;
        vector<int> volume ;
        map<P,bool> go ;

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
            reused[v] = true ;
            convert[v] = s ;
            volume[s]++ ;
            for(int i = 0 ; i < F[v].size() ; i++){
                int u = F[v][i] ;
                if(reused[u]) continue ;
                Redfs(s,u) ;
            }
        }

        void build_(){
            // 処理1 : 1度目のdfs
            for(int i = 0 ; i < n ; i++) if(!used[i]) dfs(i) ;
            // 処理2 : 2度目のdfs
            for(int i = 0 ; i < n ; i++) {
                int v = order[n-1-i] ;
                if(reused[v]) continue ;
                Redfs(new_node,v) ;
                new_node++ ;
            }
            H.resize(new_node) ;
            // 処理3 : 新しいグラフを作成する
            for(int v = 0 ; v < n ; v++){
                for(int u : G[v]){
                    int from = convert[v] , to = convert[u] ;
                    if(from == to) continue ;
                    if(go[P(from,to)]) continue ;
                    go[P(from,to)] = true ;
                    H[from].push_back(to) ;
                }
            }
        }

        inline void add_edge_(int v , int u) {
            G[v].push_back(u) ;
            F[u].push_back(v) ;
        }

    public :
        vector<vector<int>> H ;
        // n_ : グラフのノード数
        SCC(int n_){
            n = n_ ;
            G.resize(n) ; F.resize(n) ;
            used.resize(n,false) ; reused.resize(n,false) ;
            convert.resize(n) ;
            volume.resize(n) ;
            new_node = 0 ;
        }
        
        void build() { build_() ; }
        void add_edge(int v , int u) { add_edge_(v,u) ; }
        int convert(int v) {return convert[v] ; } // ノード v は新たなグラフ H 上においてどのノードに変化するか
        int get_new_gragh_size(){ return new_node ; }
        int get_integrated_node_size(int v){ return volume[v] ; }
        vector<vector<int>> get_new_gragh() { return H ; }

        inline vector<int>& operator [] (int v) { return H[v] ; } 
} ;

// build()                     : ビルドを行う
// add_edge(u,v)               : 有向辺 G と逆辺 F を張る
// convert(u)                  : 元のノード u がどの新たなグラフでいうどのノードに変異したか
// get_new_gragh_size()        : 新しく作られたグラフのノード数, 新しいグラフのノード番号は 0-indexed {0,1,2,3,4,..,new_node-1}
// get_integrated_node_size(u) : 新たなグラフのノード (0-indexed) には,前のグラフの幾つ分のノードの個数が集約されているか
// get_new_gragh()             : 新しく作られたグラフ
// *注意* SCCにより生成された新たなグラフは 0-indexedのグラフである
// このままコピペ奨励

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
    scc.build() ;
    // SCC後のグラフ ( 0-indexed )
    vector<vector<int>> G = scc.get_new_gragh() ;
    // SCC後に得られたグラフのノード数
    int new_node_num = scc.get_new_gragh_size() ;
}