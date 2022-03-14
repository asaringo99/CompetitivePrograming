#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N 1000
#define INF INT_MAX

//辺を表す構造体(行き先、容量、逆辺)
struct edge{
    int to , cap , rev ;
};

vector<edge> G[MAX_N] ; //グラフの隣接リスト表現
bool used[MAX_N] ; //DFSですでに調べたかのフラグ

// fromからtoへ向う容量capの辺をグラフに追加する
void add_edge(int from , int to , int cap){
    G[from].push_back((edge){to , cap , G[to].size()}) ;
    G[to].push_back((edge){from , 0 , G[from].size()-1}) ;
}

//増加パスをDFSで探す
int dfs(int v , int t , int f){ // v : 今いる頂点 , t : 終点(シンク) , f : 流量
    if(v == t) return f ;
    used[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge &e = G[v][i] ;
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to , t , min(f , e.cap)) ;
            if(d > 0){
                e.cap -= d ;
                G[e.to][e.rev].cap += d ;
                return d ;
            }
        }
    }
    return 0 ;
}

// sからtへの最大流を求める
int max_flow(int s , int t){
    int flow = 0 ;
    for( ; ; ){
        memset(used,0,sizeof(used)) ;
        int f = dfs(s,t,INF) ;
        if(f == 0) return flow ;
        flow += f ;
    }
}