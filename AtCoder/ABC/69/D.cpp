#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define MAX_N 100

int H , W , n ;

int main(){
  cin >> H >> W >> n ;
  int A[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  
  int count = 0 , tmp = 0 , color = 1 ;
  int V[W] ;
  for(int i = 0 ; i < H * W ; i++){
    if(count == A[tmp]){
      tmp++ ;
      color++ ;
      count = 0 ;
    }
    count++ ;
    V[i % W] = color ;
    if( (i + 1) % W == 0 ){
      if( (i + 1) % (2 * W) == 0 ){
        for(int u = W - 1 ; u >= 0 ; u--) cout << V[u] << " " ;
        cout << endl ;
        fill(V,V+W,0) ;
      }
      else{
        for(int u = 0 ; u < W ; u++) cout << V[u] << " " ;
        cout << endl ;
        fill(V,V+W,0) ;
      }
    }
  }
}