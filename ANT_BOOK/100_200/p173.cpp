#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)20
#define INF (ll)1e8

int n ;
int d[MAX_N][MAX_N] ;
int dp[MAX_N][MAX_N] ;

// すでに訪れた頂点がS、現在一がv
int TSP(int S , int v){

  //初めdpを-1で初期化している
  if(dp[S][v] >= 0){
    return dp[S][v] ;
  }

  //全ての頂点を訪れて戻ってきた
  if(S == (1 << n) - 1 && v == 0){
    return dp[S][v] = 0 ;
  }

  int res = INF ;
  for(int u = 0 ; u < n ; u++){
    if(!(S >> u & 1)){
      res = min(res,TSP(S | 1 << u , u) + d[v][u]) ;
    }
  }
  return dp[S][v] = res ;
}



int main(){
  int k ;
  cin >> n >> k ;
  memset(dp , -1 , sizeof(dp)) ;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      d[i][j] = INF ;
    }
  }
  for(int i = 0 ; i < k ; i++){
    int u , v , c ;
    cin >> u >> v >> c ;
    d[u][v] = c ;
  }
  cout << TSP(0,0) << endl ;
}