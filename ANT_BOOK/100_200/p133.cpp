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

int k , n ;
int w[INF] , v[INF] ;

bool solve(int x){
  double wv[n] ;
  ll sum = 0 ;

  for(int i = 0 ; i < n ; i++) wv[i] = v[i] - x * w[i] ;
  sort(wv,wv+n) ;
  for(int i = 0 ; i < k ; i++) sum += wv[n - 1 - i] ;
  if(sum >= k) return true ;
  else return false ;
}

int main(){
  cin >> n >> k ;
  for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i] ;
  double lef = 0 , rig = INF ;
  double ans ;
  for(int i = 0 ; i < 100 ; i++){
    double mid = (lef + rig) / 2 ;
    if(solve(mid)){
      ans = mid ;
      lef = mid + 1 ;
    }
    else rig = mid ;
  }
  cout << ans << endl ;
}