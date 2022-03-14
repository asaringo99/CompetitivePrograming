#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using Pair = pair<int,int> ;
using ll = long long ;
using que = queue<Pair> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define N 105
#define INFO 100000005

int n , m ;
char lake[N][N] ;

void dfs(int x , int y){
  lake[x][y] = 'W' ;
  for(int dx = -1 ; dx <= 1 ; dx++){
    for(int dy = -1 ; dy <= 1 ; dy++){
      if(dx == 0 && dy == 0) continue ;
      int u = x + dx ;
      int v = y + dy ;
      if(u >= 0 && v >= 0 && u < n && v < m && lake[u][v] == '.') dfs(u,v) ;
    }
  }
}

int main(){
  int count = 0 ;
  cin >> n >> m ;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      cin >> lake[i][j] ;
    }
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(lake[i][j] == '.'){
        count++ ;
        dfs(i,j) ;
      }
    }
  }
  cout << count << endl ;
}