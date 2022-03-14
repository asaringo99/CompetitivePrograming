#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int MAX_N = 100007 ;

int n , m ;
vector<int> G[MAX_N] ;
int d[MAX_N] ;
int parent[MAX_N] ;

void bfs(){
    queue<int> que ;
    que.push(0) ;
    d[0] = 0 ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] >= 0){
                if(parent[v] == -1) parent[u] = v ;
                else parent[u] = parent[v] ;
            }
        }
    }
}

int main(){
    memset(d,-1,sizeof(d)) ;
    memset(parent,-1,sizeof(parent)) ;
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ; 
        b-- ;
        G[a].push_back(b) ;
    }
}