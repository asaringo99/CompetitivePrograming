#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 200005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

int s , t ;

struct edge
{
    int to , cap , rev ;
};

vector<edge> G[MAX_N] ;
bool used[MAX_N] ;

int dfs(int v , int t , int f){
    if(v == t) return f ;
    used[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge &e = G[v][i] ;
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to,t,min(f,e.cap)) ;
            if(d > 0){
                e.cap -= d ;
                G[e.to][e.rev].cap += d ;
                return d ;
            }
        }
    }
    return 0 ;
}

int max_flow(int s , int t){
    int f = 0 ;
    while(true){
        memset(used,0,sizeof(used)) ;
        int val = dfs(s,t,INT_MAX) ;
        if(val == 0) break ;
        f += val ;
    }
    return f ;
}

int main(){
    cin >> n >> m ;
    int s = 0 , t = n + m + 1 ;
    for(int i = 1 ; i <= n ; i++){
        int node ;
        cin >> node ;
        for(int j = 0 ; j < node ; j++){
            int u ;
            cin >> u ;
            G[i].push_back(edge{n+u,1,G[n+u].size()}) ;
            G[n+u].push_back(edge{i,0,G[i].size()-1}) ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        G[0].push_back(edge{i,1,G[i].size()}) ;
        G[i].push_back(edge{0,0,G[0].size()-1}) ;
    }
    for(int i = 1 ; i <= m ; i++){
        G[n+i].push_back(edge{n+m+1,1,G[n+m+1].size()}) ;
        G[n+m+1].push_back(edge{n+i,0,G[n+i].size()-1}) ;
    }
    cout << max_flow(s,t) << endl ;
}