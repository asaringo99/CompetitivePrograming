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
#define INFO 10000000

int n ;
int a[N] ;

int solve(){
  int ans = 0 ; int res = 0 ;
  int dp[n] ;
  fill(dp,dp+n,INFO) ;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < i + 1 ; j++){
      if(dp[j] > a[i]){
        dp[j] = a[i] ;
        res = j ;
        break ;
      }
    }
    for(int i = 0 ; i < n ; i++) cout << dp[i] << " " ;
    cout << "" << endl ;
    ans = max(ans,res) ;
  }
  return ans + 1 ;
}

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  cout << solve() << endl ;
}