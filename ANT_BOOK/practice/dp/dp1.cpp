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
#define INFO 100000

int n , W ;
int w[N] , v[N] ;

int nupsuck(){
  int dp[n+1][W+1] ;
  for(int i = 0 ; i < W + 1 ; i++) dp[0][i] = 0 ;
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 0 ; j < W + 1 ; j++){
      if(j - w[i-1] >= 0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]] + v[i-1]) ;
      else dp[i][j] = dp[i-1][j] ;
    }
  }
  return dp[n][W] ;
}

int main(){
  cin >> n >> W ;
  for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i] ;
  cout << nupsuck() << endl ;
}