#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
vector<int> G[202020] ;
vector<TP> query[202020] ;
ll dist[202020] ;
ll res[202020] ;

void dfs(int v , int prev , int dep){
    vector<int> vec ;
    for(TP tp : query[v]){
        int id , d ;
        tie(id,d) = tp ;
        vec.push_back(dist[d]) ;
    }
    dist[dep]++ ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v,dep+1) ;
    }
    int i = 0 ;
    for(TP tp : query[v]){
        int id , d ;
        tie(id,d) = tp ;
        res[id] = dist[d] - vec[i] ;
        i++ ;
    }
}


int main(){
    cin >> n ;
    rrep(i,1,n){
        int p ;
        cin >> p ;
        p-- ;
        G[i].push_back(p) ;
        G[p].push_back(i) ;
    }
    cin >> q ;
    rep(i,q){
        int u , d ;
        cin >> u >> d ;
        query[--u].push_back({i,d}) ;
    }
    dfs(0,-1,0) ;
    rep(i,q) cout << res[i] << endl ;
}