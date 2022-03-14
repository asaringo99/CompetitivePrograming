#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

ll k ;

int main(){
  cin >> k ;
  ll count = 1 ; 
  int seven = 7 ;
  while(seven % k != 0 && k % 2 != 0 && count <= 1000001){
    if(seven / k == 0){
      seven = seven * 10 + 7 ;
      count = count + 1 ;
    }
    else{
      seven = (seven % k) * 10 + 7 ;
      count = count + 1 ;
    }
  }
  if(k % 2 == 0 || count >= 1000000) cout << -1 << endl ;
  else cout << count << endl ;
}