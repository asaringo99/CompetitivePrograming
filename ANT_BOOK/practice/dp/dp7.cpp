#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using Pair = pair<int,int> ;
using ll = long long ;
using que = queue<Pair> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define N 1005
#define INFO 10000

int n , m , M ;

int solve(){
  int dp[m+1][n+1] ;
  for(int i = 0 ; i < n + 1 ; i++) dp[0][i] = 0 ;
  dp[0][0] = 1 ;

  for(int i = 1 ; i < m + 1 ; i++){
    for(int j = 0 ; j < n + 1 ; j++){
      if(i > j) dp[i][j] = dp[i-1][j] ;
      else dp[i][j] = dp[i-1][j] + dp[i][j-i] ;
    }
  }
  return dp[m][n] ;
}

int main(){
  cin >> n >> m >> M ;
  cout << solve() << endl ;
}