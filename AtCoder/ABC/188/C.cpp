#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  ll N = 1 ;
  for(int i = 0 ; i < n - 1 ; i++){
    N *= 2 ;
  }

  ll max_x = 0 , max_y = 0 , ind_x , ind_y ;

  for(int i = 0 ; i < N ; i++){
    int X ;
    cin >> X ;
    if(max_x < X){
      max_x = X ;
      ind_x = i + 1 ;
    }
  }

  for(int i = 0 ; i < N ; i++){
    int Y ;
    cin >> Y ;
    if(max_y < Y){
      max_y = Y ;
      ind_y =  N + i + 1 ;
    }
  }

  if(max_x > max_y) cout << ind_y << endl ;
  else cout << ind_x << endl ;
}