#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int A[n] , B[n] , C[n-1] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i < n ; i++) cin >> B[i] ;
  for(int i = 0 ; i < n - 1 ; i++) cin >> C[i] ;

  int ans = 0 ;
  for(int i = 0 ; i < n ; i++){
    ans += B[i] ;
  }

  for(int i = 0 ; i < n - 1 ; i++){
    if(A[i+1] - A[i] == 1) ans += C[A[i]-1] ;
  }
  cout << ans << endl ;
}