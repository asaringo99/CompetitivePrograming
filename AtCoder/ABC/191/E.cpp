#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 2000
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

struct edge
{
    int to , cost ;
};

int n , m ;
int d[MAX_N][MAX_N] ;
vector<edge> G[MAX_N] ;

void dijkstra(int s){
    fill(d[s],d[s]+n,INT_MAX) ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second , dis = p.first ; 
        if(d[s][v] < dis) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[s][e.to] > dis + e.cost){
                d[s][e.to] = dis + e.cost ;
                que.push(P(d[s][e.to],e.to)) ;
            }
        }
    }
}
/*
int rec(int s){
    int res = INT_MAX ;
    for(int i = 0 ; i < G[s].size() ; i++){
        edge e = G[s][i] ;
        int u = e.to ;
        res = min(res,d[u][s]) ;
    }
    return res ;
}
*/

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        u-- ; v-- ;
        edge E ;
        E.cost = w ;
        E.to = v ;
        G[u].push_back(E) ;
    }
    for(int i = 0 ; i < n ; i++) dijkstra(i) ;
    for(int i = 0 ; i < n ; i++){
        int res = d[i][i] == INT_MAX ? -1 : d[i][i] ;
        cout << res << endl ;
    }
    /*
    for(int i = 0 ; i < n ; i++) cout << rec(i) << endl ;
    */
}