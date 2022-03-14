#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 65000
#define INF 10007

int n , S ;
int a[INF] ;
int sum[INF+1] ;

int solve(){
  for(int i = 0 ; i < n ; i++) sum[i+1] = sum[i] + a[i] ;

  if(sum[n] < S){
    return -1 ;
  }

  int res = n ;
  for(int s = 0 ; sum[s] + S <= sum[n] ; s++){
    int t = lower_bound(sum+s,sum+n,sum[s]+S) - sum ;
    res = min(res,t-s) ;
  }
  return res ;
}

int main(){
  cin >> n >> S ;
  for(int i = 0 ; i < n ; i++){
    cin >> a[i] ;
  }
  if(solve() == -1) cout << "NO" << endl ;
  else cout << solve() << endl ;
}