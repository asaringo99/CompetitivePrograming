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

int n , K ;
int a[N] , m[N] ;

int solve(){
  int dp[n+1][K+1] ;
  for(int i = 0 ; i < K + 1 ; i++) dp[0][i] = 0 ;
  dp[0][0] = 1 ;
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 0 ; j < K + 1 ; j++){
      if(dp[i-1][j]  > 0) dp[i][j] = m[i-1] ;
      else if(j - a[i-1] < 0 &&  dp[i][j-a[i-1]] <= 0) dp[i][j] = dp[i][j-a[i-1]] - 1 ;
    }
  }
}