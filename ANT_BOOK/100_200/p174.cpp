#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)20
#define INF (ll)1e8

int n ;
int dp[(1 << MAX_N) - 1][MAX_N] ;
int d[MAX_N][MAX_N] ;

int main(){
  cin >> n ;
  dp[(1 << n) - 1][0] = 0 ;
  for(int S = (1 << n) - 2 ; S >= 0 ; S--){
    for(int u = 0 ; u < n ; u++){
      for(int v = 0 ; v < n ; v++){
        if(!(S >> v & 1)) dp[S][u] = min(dp[S][u],dp[S | (1 << v)][v] + d[u][v]) ;
      }
    }
  }
}