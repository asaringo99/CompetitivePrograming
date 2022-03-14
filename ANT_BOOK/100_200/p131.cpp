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
#define INF 1000007

int n , m ;
ll x[INF] ;

int solve(int val){
  int fir = 0 ;
  for(int i = 1 ; i < m ; i++){
    int cnt = fir + 1 ;
    while(cnt < n && x[cnt] - x[fir] < val){
      cnt++ ;
    }
    if(cnt == n) return false ;
    fir = cnt ;
  }
  return true ;
}

int main(){
  cin >> n >> m ;
  for(int i = 0 ; i < n ; i++) cin >> x[i] ;
  sort(x,x+n) ;
  int lef = 0 , rig = INF ;
  int mid , ans ;
  while(rig - lef > 0){
    mid = (lef + rig) / 2 ;
    if(solve(mid)){
      lef = mid + 1 ;
      ans = mid ;
    }
    else rig = mid ;
  }
  cout << ans << endl ;
}