#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge
{
    int to ;
    ll cost ;
};


int n , m , t ;
ll A[101010] ;
vector<ll> d1, d2 ;

vector<edge> G[101010] , F[101010] ;

void dijkstra(vector<edge> G[], vector<ll> &d){
    d.resize(101010) ;
    rep(i,n) d[i] = 1e18 ;
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
    cin >> n >> m >> t ;
    rep(i,n) cin >> A[i] ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        F[b].push_back(edge{a,c}) ;
    }
    dijkstra(G,d1) ;
    dijkstra(F,d2) ;
    ll res = 0 ;
    rep(i,n){
        res = max(res,(t - d1[i] - d2[i]) * A[i]) ;
    }
    cout << res << endl ;
}