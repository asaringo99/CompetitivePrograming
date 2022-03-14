#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge{
    int to ;
    ll cost ;
} ;

int n , m ;
map<P,bool> mp ;
int d[110] , prevv[110] ;
vector<edge> G[110] ;

void djikstra(int s){
    rep(i,n) d[i] = 1e8 ;
    d[s] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
                prevv[e.to] = v ;
            }
        }
    }
    rep(i,n){
        int v = i ;
        while(v != s){
            int u = v ;
            v = prevv[v] ;
            if(v > u) mp[P(u,v)] = true ;
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,c}) ;
        G[b].push_back(edge{a,c}) ;
    }
    rep(i,n) djikstra(i) ;
    for(auto it : mp) m-- ;
    cout << m << endl ;
}