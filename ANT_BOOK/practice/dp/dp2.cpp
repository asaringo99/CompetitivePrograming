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
#define INFO 100000

int n , m ;
char s[N] , t[N] ;

void solve(){
  int dp[n+1][m+1] ;
  for(int i = 0 ; i < n + 1 ; i++) dp[i][0] = 0 ;
  for(int i = 0 ; i < m + 1 ; i++) dp[0][i] = 0 ;
  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 1 ; j < m + 1 ; j++){
      if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1 ;
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
    }
  }
  cout << dp[n][m] << endl ; 
}

int main(){
  cin >> n >> m ; 
  for(int i = 0 ; i < n ; i++) cin >> s[i] ;
  for(int i = 0 ; i < m ; i++) cin >> t[i] ;
  solve() ;
}