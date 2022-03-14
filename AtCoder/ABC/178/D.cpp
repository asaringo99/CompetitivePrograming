#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
#define M 1000000007

int s ;

int main(){
  cin>> s ;
  V_2 dp(s+1,vector<int>(s+1,0)) ;
  for(int i = 0 ; i < s + 1 ; i++) dp[i][0] = 1 ;
  for(int i = 1 ; i < s + 1 ; i++){
    for(int j = 3 ; j < s + 1 ; j++){
      dp[i][j] = (dp[i][j-1] + dp[i-1][j-3]) % M ;
      //cout << i << " " << j << " " << dp[i][j] << endl ;
    }
  }
  cout << dp[s][s] << endl ;
}