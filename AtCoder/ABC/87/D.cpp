#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

struct edge{
    int to ; 
    ll cost ;
} ;

vector<edge> G[MAX_N] ;
ll d[MAX_N] ;
bool used[MAX_N] ;

bool bfs(){
    bool ok = true ;
    memset(used,0,sizeof(used)) ;
    fill(d,d+n,INT_MAX) ;
    for(int i = 0 ; i < n ; i++){
        if(used[i]) continue ;
        queue<int> que ;
        que.push(i) ;
        d[i] = 0 ;
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            used[v] = true ;
            for(int j = 0 ; j < G[v].size() ; j++){
                edge e = G[v][j] ;
                if(d[e.to] == INT_MAX){
                    d[e.to] = d[v] + e.cost ;
                    que.push(e.to) ;
                }
                else if(d[e.to] != d[v] + e.cost) ok = false ;
            }
        }
    }
    return ok ;
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int l , r ;
        ll D ;
        cin >> l >> r >> D ;
        l-- ;
        r-- ;
        G[l].push_back(edge{r,D}) ;
        G[r].push_back(edge{l,-D}) ;
    }
    bool res = bfs() ;
    if(res) YES ;
    else NO ;
}