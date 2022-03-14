#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int r1 , r2 , c1 , c2 ;

int main(){
  cin >> r1 >> c1 >> r2 >> c2 ;
  if(r1 == r2 && c1 == c2){
    cout << 0 << endl ;
    return 0 ;
  }

  if(r2 - r1 == c2 - c1 || r2 - r1 == c1 - c2){
    cout << 1 << endl ;
    return 0 ;
  }

  if(r1 > r2){
    swap(r1,r2) ;
    swap(c1,c2) ;
  }
  if(c2 < c1) swap(c1,c2) ;
  if(c2-c1 > r2-r1){
    swap(c1,r1) ;
    swap(c2,r2) ;
  }

  if((r2 - r1 == 3 && c2 - c1 == 0) || (r2 - r1 <= 2 && c2 - c1 <= 2)){
    cout << 1 << endl ;
    return 0 ;
  }

  if((r2 - r1 == 6 && c2 - c1 == 0) || (r2 - r1 <= 5 && c2 - c1 <= 2)){
    cout << 2 << endl ;
    return 0 ;
  }

  if(r2 - (r1 + (c2 - c1)) <= 3){
    cout << 2 << endl ;
    return 0 ;
  }

  if((r2 - (r1 + (c2 - c1)) ) % 2 == 0 ){
    cout << 2 << endl ;
    return 0 ;
  }
  else{
    cout << 3 << endl ;
    return 0 ;
  }
}