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

int n ;
int a[N] ;

int solve(){
  int ans = 0 ;
  int dp[N] ;
  for(int i = 0 ; i < n ; i++){
    dp[i] = 1 ;
    for(int j = 0 ; j < i ; j++){
      if(a[i] > a[j]) dp[i] = max(dp[i],dp[j] + 1) ;
    }
    ans = max(ans,dp[i]) ;
  }
  return ans ;
}

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  cout << solve() << endl ;
}