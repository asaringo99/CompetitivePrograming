#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int A[n] ;
  int maxA = 0 , count = 0 , res = 0 ;
  for(int i = 0 ; i < n ; i++){
    cin >> A[i] ;
    if(maxA <= A[i]) maxA = a[i] ;
  }
  for(int i = 2 ; i <= maxA ; i++){
    for(int j = 0 ; j < n ; j++){
      if(A[j] % i == 0) count++ ;
    }
    if(res <= count) res = count ;
  }
  cout << res << endl ;
}