#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , x , y ;
ll res[2020] , d[2020] ;
vector<int> G[2020] ;

void bfs(int s){
    rep(i,n) d[i] = INT_MAX ;
    d[s] = 0 ;
    queue<int> que ;
    que.push(s) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                if(s < u) res[d[u]]++ ;
                que.push(u) ;
            }
        }
    }
}

int main(){
    cin >> n >> x >> y ;
    rep(i,n-1){
        G[i].push_back(i+1) ;
        G[i+1].push_back(i) ;
    }
    x-- ;
    y-- ;
    G[x].push_back(y) ;
    G[x].push_back(y) ;
    rep(i,n) bfs(i) ;
    rrep(i,1,n) cout << res[i] << endl ;
}