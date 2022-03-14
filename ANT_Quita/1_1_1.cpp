#include <bits/stdc++.h>
using namespace std ;
using V = vector<int> ;

int nibunki(V val ,int d){
  int i ;
  int f = 0 , l = val.size() ;
  while(l - f >= 1){
    i = (f + l) / 2 ;
    if(val[i] == d) return val[i] ;
    else if(val[i] < d) f = i + 1 ;
    else l = i ;
  }
  return val[f-1] ;
}

int main(){
  int n , k , x ;
  cin >> n >> k ;
  int D = k + 1 , ans = 0 ;
  V A(n+1) ;
  A[0] = 0 ;
  for(int i = 0 ; i < n ; i++) cin >> A[i+1] ;
  V val ;
  for(int i = 0 ; i < n + 1 ; i++){
    for(int j = 0 ; j < n + 1 ; j++){
      if(A[i] + A[j] > k) continue ;
      val.push_back(A[i] + A[j]) ;
    }
  }
  sort(val.begin(),val.end()) ;

  for(int i = 0 ; i < n + 1 ; i++){
    if(k < x) continue ;
    for(int j = 0 ; j < n + 1 ; j++){
      x = A[i] + A[j] ;
      if(k < x) continue ;
      if(k - nibunki(val,k-x) - x < D){
        D = k - nibunki(val,k-x) - x ;
        ans = k - D ;
      }
    }
  }
  cout << ans << endl ;
}