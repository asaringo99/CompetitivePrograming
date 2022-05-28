#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
            }
        }
        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x ;
            else return par[x] = root(par[x]) ;
        }

        //xとyの属する集合を合併
        void unite(int x , int y){
            x = root(x);
            y = root(y) ;
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
} ;

struct edge{
    int to ;
    ll cost ;
};

int n , m ;
TP X[202020] ;
vector<edge> G[202020] ;

ll d[202020] ;
int prevv[202020] ; // 一個前のノード
map<P,int> mp ;

// 始点: s , 終点: t
void djikstra(){
    rep(i,n) d[i] = 1e17 ;
    rep(i,n) prevv[i] = -1 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                prevv[e.to] = v ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

vector<int> res ;

int main(){
    fast_input_output
    cin >> n >> m ;
    UnionFind uf(n) ;
    rep(i,m){
        int a , b ;
        ll c;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        mp[P(max(a,b),min(a,b))] = i ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    djikstra() ;
    vector<P> vec ;
    rep(i,n) vec.push_back(P(d[i],i)) ;
    sort(vec.begin(),vec.end(),greater<P>()) ;
    rep(i,n){
        // 始点から終点までの経路を復元する
        auto [dist,id] = vec[i] ;
        int v = id ;
        while(prevv[v] != -1){
            int u = prevv[v] ;
            if(uf.same(v,u)) break;
            uf.unite(u,v) ;
            res.push_back(mp[P(max(v,u),min(v,u))]) ;
            v = prevv[v] ;
        }
    }
    for(int u : res) cout << u + 1 << " " ; cout << endl ;
}