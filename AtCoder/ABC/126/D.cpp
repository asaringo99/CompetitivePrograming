#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

struct edge
{
    int to ;
    ll cost ;
};

vector<edge> G[MAX_N] ;
ll d[MAX_N] ;

void dijkstra(){
    fill(d,d+n,LLONG_MAX) ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n - 1 ; i++){
        int u , v ;
        ll w ;
        cin >> u >> v >> w ;
        u-- ;
        v-- ;
        G[u].push_back(edge{v,w}) ;
        G[v].push_back(edge{u,w}) ;
    }
    dijkstra() ;
    for(int i = 0 ; i < n ; i++){
        if(d[i] % 2 == 0) cout << 1 << endl ;
        else cout << 0 << endl ;
    }
}