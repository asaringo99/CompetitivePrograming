#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int x[n] , y[n] ;
  for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] ;

  int count = 0 ;
  for(int i = 0 ; i < n - 1 ; i++){
    for(int j = i + 1 ; j < n ; j++){
      int dx = abs(x[j] - x[i]) , dy = abs(y[j] - y[i]) ;
      if(dy <= dx) count++ ;
    }
  }
  cout << count << endl ;
}