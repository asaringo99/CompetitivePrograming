#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 10007 ;

struct edge
{
    int to , rev ;
    ll cap ;
};

vector<edge> G[MAX_N] ;
int level[MAX_N] , iter[MAX_N] ;

void add_edge(int from , int to , ll cap){
    G[from].push_back(edge{to,(int)G[to].size(),cap}) ;
    G[to].push_back(edge{from,(int)G[from].size()-1,0}) ;
}

void bfs(int s){
    memset(level,-1,sizeof(level)) ;
    level[s] = 0 ;
    queue<int> que ;
    que.push(s) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(e.cap > 0 && level[e.to] == -1){
                level[e.to] = level[v] + 1 ;
                que.push(e.to) ;
            }
        }
    }
}

ll dfs(int v , int t , ll f){
    if(v == t) return f ;
    for(int &i = iter[v] ; i < G[v].size() ; i++){
        edge &e = G[v][i] ;
        if(e.cap > 0 && level[e.to] > level[v]){
            ll d = dfs(e.to,t,min(f,e.cap)) ;
            if(d > 0){
                e.cap -= d ;
                G[e.to][e.rev].cap += d ;
                return d ;
            }
        }
    }
    return 0 ;
}

ll max_flow(int s , int t){
    ll flow = 0 ;
    for(;;){
        bfs(s) ;
        if(level[t] == -1) return flow ;
        ll f ;
        memset(iter,0,sizeof(iter)) ;
        while((f = dfs(s,t,LLONG_MAX)) > 0){
            flow += f ;
        }
    }
}

// AOJ Maximum Flow
int v , e ;
int main(){
    cin >> v >> e ;
    rep(i,e){
        int a , b , c ;
        cin >> a >> b >> c ;
        add_edge(a,b,c) ;
    }
    cout << max_flow(0,v-1) << endl ;
}