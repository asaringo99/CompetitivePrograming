#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e9+7

int n , r ;
int x[M] ;

int binary_tree(int k){
  int lef = 0 , rig = n ;
  while(lef < rig){
    int half = (rig + lef) / 2 ;
    if(x[half] == k) return half ;
    else if(x[half] < k) lef = half + 1 ;
    else rig = half ;
  }
  return rig - 1 ;
}

int main(){
  cin >> n >> r ;
  for(int i = 0 ; i < n ; i++) cin >> x[i] ;
  sort(x,x+n) ;
  int i = 0 , cnt = 0 ;
  while(i < n){
    i = binary_tree(x[i] + r) ;
    i = binary_tree(x[i] + r) ;
    cnt++ ; i++ ;

  }
  cout << cnt << endl ;
}