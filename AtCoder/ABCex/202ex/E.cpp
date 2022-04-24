#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
vector<int> G[200007] ;
vector<TP> query[200007] ;
int ans[200007] ;
int num_dep[200007] ;

void dfs(int v , int prev , int dep){
    vector<int> que(query[v].size()) ;
    for(int i = 0 ; i < query[v].size() ; i++){
        int id , depth ;
        tie(id,depth) = query[v][i] ;
        que[i] = num_dep[depth] ;
    }
    num_dep[dep]++ ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u != prev) dfs(u,v,dep+1) ;
    }
    for(int i = 0 ; i < query[v].size() ; i++){
        int id , depth ;
        tie(id,depth) = query[v][i] ;
        ans[id] = num_dep[depth] - que[i] ;
    }
}

int main(){
    memset(num_dep,0,sizeof(num_dep)) ;
    cin >> n ;
    rrep(i,1,n){
        int a ;
        cin >> a ;
        a-- ;
        G[i].push_back(a) ;
        G[a].push_back(i) ;
    }
    cin >> q ;
    rep(i,q){
        int u , d ;
        cin >> u >> d ;
        u-- ;
        query[u].push_back({i,d}) ;
    }
    memset(num_dep,0,sizeof(num_dep)) ;
    dfs(0,-1,0) ;
    for(int i = 0 ; i < q ; i++){
        cout << ans[i] << endl ;
    }
}