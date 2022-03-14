#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<ll,int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m , s , t ;
vector<int> G[101010] ;
ll d[101010][3] ;

void dijkstra(int s , int t){
    rep(i,n) rep(j,3) d[i][j] = 1e18 ;
    d[s][0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push({0,0,s}) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        ll dist , cnt , v ;
        tie(dist,cnt,v) = p ;
        if(d[v][cnt] < dist) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(cnt == 2) {
                if(d[u][0] > d[v][cnt] + 1){
                    d[u][0] = d[v][cnt] + 1 ;
                    que.push({d[u][0],0,u}) ;
                }
            }
            else {
                if(d[u][cnt+1] > d[v][cnt]){
                    d[u][cnt+1] = d[v][cnt] ;
                    que.push({d[u][cnt+1],cnt+1,u}) ;
                }
            }
        }
    }
    cout << (d[t][0] == 1e18 ? -1 : d[t][0]) << endl  ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
    }
    cin >> s >> t ;
    s-- ; t-- ;
    dijkstra(s,t) ;
}