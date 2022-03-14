#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e5

int n , m ;

vector<int> G[MAX_N] ;
int node_number[MAX_N] ;
bool used[MAX_N] ;

void bfs(){
    for(int i = 0 ; i < n ; i++){
        if(used[i]) continue ;
        queue<int> que ;
        que.push(i) ;
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            if(used[v]) continue ;
            used[v] = true ;
            node_number[v] = i ;
            for(int j = 0 ; j < G[v].size() ; j++){
                int u = G[v][j] ;
                if(!used[u]) que.push(u) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int x , y , z ;
        cin >> x >> y >> z ;
        x-- ; y-- ;
        G[x].push_back(y) ;
        G[y].push_back(x) ; 
    }
    bfs() ;
    set<int> S ;
    for(int i = 0 ; i < n ; i++){
        S.insert(node_number[i]) ;
    }
    cout << S.size() << endl ;
}