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
#define INFO 1000

int n , m , M ;
int a[INFO] ;

int solve(){
  int dp[n+1][m+1] ;
  for(int i = 0 ; i < n + 1 ; i++) dp[i][0] = 1 ;
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 1 ; j < m + 1 ; j++){
      if(j-1 >= a[i-1]) dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-a[i-1]] ;
      else dp[i][j] = dp[i][j-1] + dp[i-1][j] ;
    }
  }
  return dp[n][m] ;
}

int main(){
  cin >> n >> m >> M ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  cout << solve() << endl ;
}