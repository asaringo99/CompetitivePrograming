#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e8+7

int n , m ;

int main(){
  cin >> n >> m ;
  char s[n] , t[m] ;
  cin >> s >> t ;
  int dp[n+1][m+1] ;
  for(int i = 0 ; i < n + 1 ; i++){
    dp[i][0] = 0 ;
  }
  for(int j = 0 ; j < m + 1 ; j++){
    dp[0][j] = 0 ;
  }

  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 1 ; j < m + 1 ; j++){
      if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1 ;
      else dp[i][j] = max(dp[i][j-1],dp[i-1][j]) ;
    }
  }
  cout << dp[n][m] << endl ;
}