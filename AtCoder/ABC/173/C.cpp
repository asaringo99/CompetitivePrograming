#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

int H , W , K ;

int main(){
  cin >> H >> W >> K ;
  vector<vector<char>> checker(H,vector<char>(W)) ;
  for(int i = 0 ; i < H ; i++)
    for(int j = 0 ; j < W ; j++) cin >> checker[i][j] ;

  int res = 0 ;
  for(int i = 0 ; i < (1 << H) ; i++){
    vector<vector<char>> V = checker ;
    for(int j = 0 ; j < H ; j++){
      if(i >> j & 1){
        for(int k = 0 ; k < W ; k++){
          V[j][k] = '.' ;
        }
      }
    }
    for(int j = 0 ; j < (1 << W) ; j++){
      vector<vector<char>> U = V ;
      for(int k = 0 ; k < W ; k++){
        if(j >> k & 1){
          for(int p = 0 ; p < H ; p++){
            U[p][k] = '.' ;
          }
        }
      }
      int count = 0 ;
      for(int j = 0 ; j < H ; j++){
        for(int k = 0 ; k < W ; k++){
          if(U[j][k] == '#') count++ ;
        }
      }
      if(count == K) res++ ;
    }
  }
  cout << res << endl ;
}