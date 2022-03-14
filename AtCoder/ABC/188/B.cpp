#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int A[n] , B[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i < n ; i++) cin >> B[i] ;
  ll sum = 0 ;
  for(int i = 0 ; i < n ; i++){
    sum += (A[i] * B[i]) ;
  }
  if(sum == 0) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}