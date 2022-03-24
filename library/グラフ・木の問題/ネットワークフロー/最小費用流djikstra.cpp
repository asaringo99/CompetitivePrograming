#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 1007 ;

struct edge
{
    int to , rev ;
    ll cost , cap ;
};

int n ;
vector<edge> G[MAX_N] ;
ll dist[MAX_N] , h[MAX_N] ;
int prevv[MAX_N] , preve[MAX_N] ;

void add_edge(int from , int to, ll cost , ll cap){
    G[from].push_back(edge{to,(int)G[to].size(),cost,cap}) ;
    G[to].push_back(edge{from,(int)G[from].size()-1,-cost,0}) ;
}


ll min_flow(int s , int t , ll f){
    ll res = 0 ;
    memset(h,0,sizeof(h)) ;
    while(f > 0){
        fill(dist,dist+MAX_N,LLONG_MAX) ;
        priority_queue<P,vector<P>,greater<P>> que ;
        dist[s] = 0 ;
        que.push(P(0,s)) ;
        while(!que.empty()){
            P p = que.top() ; que.pop() ;
            int v = p.second ;
            if(dist[v] < p.first) continue ;
            for(int i = 0 ; i < G[v].size() ; i++){
                edge e = G[v][i] ;
                if(e.cap > 0 && dist[e.to] > dist[v] + h[v] - h[e.to] + e.cost){
                    dist[e.to] = dist[v] + h[v] - h[e.to] + e.cost ;
                    prevv[e.to] = v ;
                    preve[e.to] = i ;
                    que.push(P(dist[e.to],e.to)) ;
                }
            }
        }
        if(dist[t] == LLONG_MAX) return -1 ; // 総流量fを流すことができなかった
        for(int i = 0 ; i < n ; i++) h[i] += dist[i] ;
        ll d = f ;
        for(int v = t ; v != s ; v = prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap) ;
        res += h[t] * d ;
        f -= d ;
        for(int v = t ; v != s ; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]] ;
            e.cap -= d ;
            G[e.to][e.rev].cap += d ;
        }
    }
    return res ;
}

// AOJ Minimum Cost Flow
int e , f ;
int main(){
    cin >> n >> e >> f ;
    rep(i,e){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        add_edge(a,b,d,c) ;
    }
    cout << min_flow(0,n-1,f) << endl ;
}