#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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


const int MAX_N = 10007 ;

struct Dinic{
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

    inline ll dfs(int v , int t , ll f){
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

    ll getMaxFlow(int s , int t){ return max_flow(s,t) ; }
};


// AOJ Maximum Flow

int n , m , c ;
char S[1010][1010] ;
const int dx[] = {1,0} , dy[] = {0,1} ;
int d[5050][5050] ;
Dinic dinic ;

void bfs(int sx , int sy , int gx , int gy , int p){
    rep(i,n) rep(j,m) d[i][j] = 1e9 ;
    d[sx][sy] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,sx,sy}) ;
    while(!que.empty()){
        auto [dist,x,y] = que.top() ; que.pop() ;
        dinic.add_edge(p,1+c+x*n+y,dist) ;
        if(dist > d[x][y]) continue;
        for(int i = 0 ; i < 2 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= n || 0 > ny || ny >= m || S[nx][ny] == '#') continue ;
            if(d[nx][ny] > d[x][y] + 1){
                d[nx][ny] = d[x][y] + 1 ;
                que.push({dist,nx,ny}) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) rep(j,m) cin >> S[i][j];
    int c = 0 ;
    rep(i,n) rep(j,m) if(S[i][j] == 'o') c++ ;
    rep(i,n) rep(j,m) {
        if(S[i][j] == '#') continue;
        if(i+1<n && S[i+1][j] != '#') dinic.add_edge(1+i*n+j,1+(i+1)*n+j,1) ;
        if(j+1<m && S[i][j+1] != '#') dinic.add_edge(1+i*n+j,1+i*n+j+1,1) ;
    }
    cout << dinic.max_flow(0,n*m) << endl ;
}