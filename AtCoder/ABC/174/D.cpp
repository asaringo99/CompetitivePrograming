#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

int n ;
string C ;

int main(){
  cin >> n >> C ;
  int l = 0 , r = C.size() - 1 ;
  int res = 0 ;
  while(r - l > 0){
    if(C[l] == 'W' && C[r] == 'R'){
      C[l] = 'R' ; C[r] = 'W' ;
      l++ ; r-- ;
      res++ ;
    }
    else if(C[l] == 'W') r-- ;
    else if(C[r] == 'R') l++ ;
    else{
      r-- ;
      l++ ;
    }
  }
  cout << res << endl ;
}