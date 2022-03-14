#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define INF 100005
#define M 1000000007

int n , m ;
int a[INF] ;

int main(){
  cin >> n >> m ;
  ll dp[n+1] ;
  fill(dp,dp+n+1,0) ;
  for(int i = 0 ; i < m ; i++){
    int s ;
    cin >> s ;
    dp[s] = -1 ;
  }

  if(dp[1] == - 1 && dp[2] == -1){
    cout << 0 << endl ;
    return 0 ;
  }

  if(dp[1] != -1) dp[1] = 1 ;
  if(dp[1] != -1 && dp[2] != -1) dp[2] = 2 ;
  if(dp[1] == -1 && dp[2] != -1) dp[2] = 1 ;

  for(int i = 3 ; i < n + 1 ; i++){
    if(dp[i] == -1 && dp[i-1] == -1){
      cout << 0 << endl ;
      return 0 ;
    }
    if(dp[i] == -1) continue ;
    if(dp[i-2] != -1 && dp[i-1] == -1) dp[i] = dp[i-2] % M ;
    if(dp[i-1] != -1 && dp[i-2] == -1) dp[i] = dp[i-1] % M ;
    if(dp[i-1] != -1 && dp[i-2] != -1) dp[i] = (dp[i-1] + dp[i-2]) % M ;
  }
  cout << dp[n] << endl ;
}