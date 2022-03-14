#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N (ll)2e5

int n , m ;

int group_size[MAX_N] ;
bool used[MAX_N] ;
vector<int> G[MAX_N] ;

void bfs(){
  fill(group_size,group_size+n,0) ;
  for(int i = 0 ; i < n ; i++){
    if(used[i]) continue ;
    queue<int> que ;
    que.push(i) ;
    while(!que.empty()){
      int v = que.front() ; que.pop() ;
      group_size[i]++ ;
      used[v] = true ;
      for(int j = 0 ; j < G[v].size() ; j++){
        int u = G[v][j] ;
        if(used[u]) continue ;
        used[u] = true ;
        que.push(u) ;
      }
    }
  }
}

int main(){
  cin >> n >> m ;
  for(int i = 0 ; i < m ; i++){
    int a , b ;
    cin >> a >> b ;
    a-- ; b-- ;
    G[a].push_back(b) ;
    G[b].push_back(a) ;
  }
  bfs() ;
  int ans = 0 ;
  for(int i = 0 ; i < n ; i++){
    ans = max(group_size[i],ans) ;
  }
  cout << ans << endl ;
}