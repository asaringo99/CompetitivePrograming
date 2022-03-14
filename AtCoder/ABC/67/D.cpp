#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
vector<int> G[101010] ;
int d1[101010] , d2[101010] ;

void dfs1(int v , int prev , int dep){
    d1[v] = dep ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs1(u,v,dep+1) ;
    }
}

void dfs2(int v , int prev , int dep){
    d2[v] = dep ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs2(u,v,dep+1) ;
    }
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs1(0,-1,0) ; dfs2(n-1,-1,0) ;
    int f = 0 , s = 0 ;
    rep(i,n){
        if(d1[i] <= d2[i]) f++ ;
        else s++ ;
    }
    if(f > s) cout << "Fennec" << endl ;
    else cout << "Snuke" << endl ;
}