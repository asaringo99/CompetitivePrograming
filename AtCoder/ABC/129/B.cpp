#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005
#define INF 105

int n ;
int w[INF] ;

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++) cin >> w[i] ;

  int res = INF ;
  
  for(int t = 0 ; t < n - 1 ; t++){
    int sum1 = 0 , sum2 = 0 ;
    for(int i = 0 ; i <= t ; i++) sum1 += w[i] ;
    for(int i = t + 1 ; i < n ; i++) sum2 += w[i] ;
    res = min(res,abs(sum2-sum1)) ;
  }
  cout << res << endl ;
}