#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge{
    int to ;
    ll cost ;
};

int n , m ;

vector<edge> G[202020] ;
ll d[202020] ;
int prevv[202020] ; // 一個前のノード
vector<int> line ; // 経路復元

// 始点: s , 終点: t
void djikstra(int s , int t){
    rep(i,n) d[i] = 1e16 ;
    rep(i,n) prevv[i] = -1 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
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
    // 始点から終点までの経路を復元する
    int v = t ;
    while(v != -1){
        line.push_back(v) ;
        v = prevv[v] ;
    }
    reverse(line.begin(),line.end()) ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        ll v , u , c ;
        cin >> v >> u >> c ;
        v-- ; u-- ;
        G[v].push_back(edge{u,c}) ;
        G[u].push_back(edge{v,c}) ;
    }
}