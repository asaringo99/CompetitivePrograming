#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;
vector<int> G[20] ;
bool used[20] ;
int color[20] ;

ll bfs(){
    ll res = 0 , tmp = 1 ; ;
    fill(color,color+20,-1) ;
    for(int i = 0 ; i < n ; i++){
        if(used[i]){
            for(int j = 0 ; j < G[i].size() ; j++){
                if(used[G[i][j]]) return 0 ;
            }
            continue ;
        }
        if(color[i] != -1) continue ;
        queue<int> que ;
        que.push(i) ;
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            for(int j = 0 ; j < G[v].size() ; j++){
                int u = G[v][j] ;
                if(u == i) continue ;
                if(used[u]) continue ;
                if(color[v] == u) continue ;
                if(color[u] != -1) return 0 ;
                color[u] = v ;
                que.push(u) ;
            }
        }
        tmp *= 2 ;
    }
    return tmp ;
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    ll res = 0 ;
    for(int i = 0 ; i < (1 << n) ; i++){
        memset(used,0,sizeof(used)) ;
        for(int j = 0 ; j < n ; j++){
            if(i >> j & 1) used[j] = true ;
        }
        res += bfs() ;
    }
    cout << res << endl ;
}