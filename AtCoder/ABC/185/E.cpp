#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define MAX_N (ll)1e3

int n , m ;

int main(){
  cin >> n >> m ;
  char A[n] , B[m] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i < m ; i++) cin >> B[i] ;
  int dp[n + 1][m + 1] ;
  for(int i = 0 ; i < m + 1 ; i++) dp[0][i] = 0 ;
  for(int i = 0 ; i < n + 1 ; i++) dp[i][0] = 0 ;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(A[i-1] == B[j-1]) dp[i][j] =  dp[i-1][j-1] + 1 ;
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
    }
  }
  int res = dp[n][m] ;
  int sum = 0 , lenA = 0 , lenB = 0 ;
  for(int i = n ; i >= 0 ; i--){
    for(int j = m ; m >= 0 ; j--){
      if(dp[i-1][j-1] == dp[i][j] - 1){
        if(i - lenA > j - lenB) lenA++ ;
      }
    }
  }
  
  cout << ans << endl ;
}