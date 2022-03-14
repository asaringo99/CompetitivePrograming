#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct edge{
    int to ;
    ll cost ;
};

int n , m , p ;
ll d[3030] ;
vector<edge> G[3030] ;
vector<int> F[3030] , H[3030] ;
bool used1[3030] , used2[3030] ;

void bfs1(){
    rep(i,n) used1[i] = false ;
    queue<int> que;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        used1[v] = true ;
        for(int i = 0 ; i < F[v].size() ; i++){
            int u = F[v][i] ;
            if(used1[u]) continue ;
            que.push(u) ;
            used1[u] = true ;
        }
    }
}

void bfs2(){
    rep(i,n) used2[i] = false ;
    queue<int> que;
    que.push(n-1) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        used2[v] = true ;
        for(int i = 0 ; i < H[v].size() ; i++){
            int u = H[v][i] ;
            if(used2[u]) continue ;
            que.push(u) ;
            used2[u] = true ;
        }
    }
}

ll belmanford(){
    int count = 0 ;
    rep(i,n) d[i] = 1e12 ;
    d[0] = 0 ;
    while(true){
        bool update = false ;
        for(int v = 0 ; v < n ; v++){
            if(d[v] == 1e12) continue ;
            if(!used1[v] || !used2[v]) continue ;
            for(int i = 0 ; i < G[v].size() ; i++){
                edge e = G[v][i] ;
                if(!used1[e.to] || !used2[e.to]) continue ;
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost ;
                    update = true ;
                }
            }
        }
        if(!update) break ;
        count++ ;
        if(count == n + 1) break ;
    }
    if(count == n+1) return 1e10 ;
    return d[n-1] ;
}

int main(){
    cin >> n >> m >> p ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        G[a].push_back(edge{b,p-c}) ;
        F[a].push_back(b) ;
        H[b].push_back(a) ;
    }
    bfs1() ; bfs2() ;
    ll ans = belmanford() ;
    if(ans == 1e10) ans = -1 ;
    else if(ans >= 0) ans = 0 ;
    else ans = -ans ;
    cout << ans << endl ;
}