#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  ll a[n] , b[n] ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  for(int j = 0 ; j < n ; j++) cin >> b[j] ;

  ll A[n] , C[n] ;
  A[0] = a[0] ; C[0] = a[0] * b[0] ;
  cout << C[0] << endl ;
  for(int i = 1 ; i < n ; i++){
    A[i] = max(A[i-1],a[i]) ;
    C[i] = max(A[i] * b[i],C[i-1]) ;
    cout << C[i] << endl ;
  }
  return 0 ;
}