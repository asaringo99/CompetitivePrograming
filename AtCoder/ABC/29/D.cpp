#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

string S ;

int main(){
  cin >> S ;
  int n = S.size() ;

  vector<int> digit ;
  for(char u : S) digit.push_back(u - '0') ;

  ll dp[n+1][2] ;
  memset(dp,0,sizeof(dp)) ;
  dp[0][0] = 0 ;

  for(int i = 0 ; i < n ; i++){
    for(int smaller = 0 ; (i == 0 ? smaller < 1 : smaller < 2) ; smaller++){
      for(int x = 0 ; x <= (smaller ? 9 : digit[i]) ; x++){
        dp[i+1][smaller || x < digit[i]] += dp[i][smaller] + (x == 1 ? 1 : 0) + (smaller ? 9 : 0) ;
      }
    }
  }
  cout << dp[n][0] << " " << dp[n][1] << endl ;
}