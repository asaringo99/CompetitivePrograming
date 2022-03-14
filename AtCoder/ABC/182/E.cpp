#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define INF 100005

int H , W , N , M ;

int main(){
  int count = 0 ;
  cin >> H >> W >> N >> M ;
  int meiro[H][W] ;
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      meiro[i][j] = 0 ;
    }
  }
  for(int i = 0 ; i < N ; i++){
    int s , t ;
    cin >> s >> t ;
    meiro[s-1][t-1] = 1 ;
  }
  for(int i = 0 ; i < M ; i++){
    int s , t ;
    cin >> s >> t ;
    meiro[s-1][t-1] = -1 ;
  }
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      if(meiro[i][j] == 1){
        count++ ;
        meiro[i][j] = -1 ;
        for(int dy = -1 ; dy <= 1 ; dy++ ){
          for(int dx = -1 ; dx <= 1 ; dx++){
            if(abs(dx) == abs(dy)) continue ;
            int y = i + dy , x = j + dx ;
            if(y >= 0 && y < H && x >= 0 && x < W && meiro[y][x] == 0){
              meiro[y][x] = -1 ;
              count++ ;
            }
          }
        }
      }
    }
  }
  cout << count << endl ;
}
