#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N (ll)1e5

int n , m , k ;
int is_node[MAX_N+7] ;
int gragh_size[MAX_N+7] ;
vector<int> is_friend[MAX_N+7] ;
vector<int> is_block[MAX_N+7] ;

void bfs(){
  bool used[MAX_N+7] ;
  fill(used,used+n,false) ;
  for(int i = 0 ; i < n ; i++){
    if(used[i]) continue ;
    int count = 0 ;
    queue<int> que ;
    que.push(i) ;
    while(!que.empty()){
      int v = que.front() ; que.pop() ;
      if(used[v]) continue ;
      is_node[v] = i ;
      count++ ;
      used[v] = true ;
      for(int j = 0 ; j < is_friend[v].size() ; j++){
        int u = is_friend[v][j] ;
        //is_node[u] = i ;
        que.push(u) ;
      }
    }
    gragh_size[i] = count ;
  }
}

int main(){
  cin >> n >> m >> k ;
  for(int i = 0 ; i < m ; i++){
    int a , b ;
    cin >> a >> b ;
    a-- ; b-- ;
    is_friend[a].push_back(b) ;
    is_friend[b].push_back(a) ;
  }
  for(int i = 0 ; i < k ; i++){
    int a , b ;
    cin >> a >> b ;
    a-- ; b-- ;
    is_block[a].push_back(b) ;
    is_block[b].push_back(a) ;
  }

  bfs() ;

  vector<int> res ;
  for(int i = 0 ; i < n ; i++){
    int num = is_node[i] ;
    int len = gragh_size[num] ;
    int friend_number = is_friend[i].size() ;
    int block_number = 0 ;
    for(int j = 0 ; j < is_block[i].size() ; j++)
      if(is_node[is_block[i][j]] == num) block_number++ ;
    res.push_back(len - friend_number - block_number - 1) ;
  }
  for(int u : res) cout << u << " " ;
  cout << endl ;
}