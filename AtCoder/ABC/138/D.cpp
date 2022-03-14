#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , q ;
ll d[202020] ;

vector<int> G[202020] ;

void dfs(int v , int prev){
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        d[u] += d[v] ;
        dfs(u,v) ;
    }
}

int main(){
    cin >> n >> q ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    rep(i,q){
        int p , x ;
        cin >> p >> x ;
        p-- ;
        d[p] += x ;
    }
    dfs(0,-1) ;
    rep(i,n) cout << d[i] << " " ;
    cout << endl ;
}