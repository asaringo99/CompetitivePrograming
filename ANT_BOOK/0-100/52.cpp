#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e8+7

int n , W ;

int main(){
  cin >> n >> W ;
  int w[n] , v[n] ;
  for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i] ; 
  int dp[n+1][W+1] ;
  for(int i = 0 ; i < W + 1 ; i++) dp[0][i] = 0 ;
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 0 ; j < W + 1 ; j++){
      if(j - w[i-1] >= 0) dp[i][j] = max(dp[i-1][j-w[i-1]] + v[i-1],dp[i-1][j]) ;
      else dp[i][j] = dp[i-1][j] ;
    }
  }
  cout << dp[n][W] << endl ;
}