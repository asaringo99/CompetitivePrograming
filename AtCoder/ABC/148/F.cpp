#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , s , t ;
vector<int> G[100007] ;

int tkhs[101010] , aoki[101010] ;
bool useda[101010] , usedt[101010] ;

void dfsa(int v , int depth){
    aoki[v] = depth ;
    useda[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!useda[u]) dfsa(u,depth+1) ;
    }
}

void dfst(int v , int depth){
    tkhs[v] = depth ;
    usedt[v] = true ;
    if(tkhs[v] >= aoki[v]) return ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(!usedt[u]) dfst(u,depth+1) ;
    }
}

int main(){
    cin >> n >> s >> t ;
    s-- ;
    t-- ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfsa(t,0) ;
    memset(tkhs,-1,sizeof(tkhs)) ;
    dfst(s,0) ;
    int res = -1 ;
    rep(i,n) if(tkhs[i] >= 0) res = max(res,aoki[i]) ;
    cout << res - 1 << endl ;
}