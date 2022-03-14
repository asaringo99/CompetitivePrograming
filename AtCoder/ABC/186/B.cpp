#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005



int main(){
  int H , W ;
  cin >> H >> W ;
  int A[H][W] ;
  int small = 101 ;
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> A[i][j] ;
      small = min(small,A[i][j]) ;
    }
  }
  int sum = 0 ;
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      sum += (A[i][j] - small) ;
    }
  }
  cout << sum << endl ;
}