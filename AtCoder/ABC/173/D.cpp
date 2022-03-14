#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int n ;

int main(){
  cin >> n ;
  ll A[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  sort(A,A+n,greater<ll>()) ;
  if(n == 1){
    cout << 0 << endl ;
    return 0 ;
  }
  if(n == 2){
    cout << A[0] << endl ;
    return 0 ;
  }
  int i = 1 , j = 2 ;
  ll res = A[0] ;
  while(j < n){
    if(j % 2 != 1) res += A[i] ;
    else{
      res += A[i] ;
      i++ ;
    }
    j++ ;
  }
  cout << res << endl ;
}