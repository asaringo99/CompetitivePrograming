#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

struct edge{
    int from , to ;
    ll cost ;
} ;

int n , m ;
vector<int> F1[1010] , F2[1010] ;
edge G[2020] ;
bool used1[1010] , used2[1010] ;
map<int,bool> mp ;
ll d[1010] ;

void bfs1(){
    used1[0] = true ;
    queue<int> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < F1[v].size() ; i++){
            int u = F1[v][i] ;
            if(used1[u]) continue ;
            que.push(u) ;
            used1[u] = true ;
        }
    }
}

void bfs2(){
    used2[n-1] = true ;
    queue<int> que ;
    que.push(n-1) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < F2[v].size() ; i++){
            int u = F2[v][i] ;
            if(used2[u]) continue ;
            que.push(u) ;
            used2[u] = true ;
        }
    }
}

void f(){
    bfs1() ;
    bfs2() ;
    rep(i,n){
        if(used1[i] && used2[i]) mp[i] = false ;
        else mp[i] = true ;
    }
}

ll g(){
    rep(i,n) d[i] = 1e16 ;
    d[0] = 0 ;
    int count = 1010 ;
    while(count > 0){
        bool update = false ;
        for(int i = 0 ; i < m ; i++){
            edge e = G[i] ;
            if(mp[e.from] || mp[e.to]) continue ;
            if(d[e.to] > d[e.from] + e.cost){
                update = true ;
                d[e.to] = d[e.from] + e.cost ;
            }
        }
        if(!update) break ;
        count-- ;
    }
    if(count == 0) return 1e18 ;
    return d[n-1] ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        F1[a].push_back(b) ;
        F2[b].push_back(a) ;
        G[i] = edge{a,b,-c} ;
    }
    f() ;
    ll res = g() ;
    if(res == 1e18) cout << "inf" << endl ;
    else cout << -res << endl ;
}