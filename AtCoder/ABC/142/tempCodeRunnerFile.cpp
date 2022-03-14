#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"


int n , m , node = 1e8 ;
vector<int> G[1010] ;
int d[1010] ;
int prevv[1010] ;
vector<int> res ;

void djikstra(int s){
    rep(i,n) d[i] = 1e8 ;
    rep(i,n) prevv[i] = -1 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,s)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ; 
        int v = p.second , dist = p.first ;
        if(d[v] < dist) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] > dist + 1){
                d[u] = dist + 1 ;
                prevv[u] = v ;
                que.push(P(d[u],u)) ;
            }
        }
    }
    if(prevv[s] == -1) return ;
    vector<int> vec = {s+1} ;
    int v = prevv[s] ;
    while(v != s){
        vec.push_back(v+1) ;
        v = prevv[v] ;
    }
    if(vec.size() < node){
        node = vec.size() ;
        res = vec ;
    }
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
    }
    rep(i,n) djikstra(i) ;
    if(res.size() > 0){
        cout << res.size() << endl ;
        rep(i,res.size()) cout << res[i] << endl ;
    }
    else cout << -1 << endl ;
}