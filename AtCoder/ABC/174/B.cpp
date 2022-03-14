#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

int n ;
ll Z ;

int main(){
  int count = 0 ;
  cin >> n >> Z ;
  ll x[n] , y[n] ;
  for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] ;
  for(int i = 0 ; i < n ; i++){
    if(x[i]*x[i] + y[i]*y[i] <= Z*Z) count = count + 1 ;
  }
  cout << count << endl ;
}