#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int B[n] ;
  for(int i = 0 ; i < n - 1 ; i++) cin >> B[i] ;
  int ans = B[0] ;
  for(int i = 0 ; i < n - 2 ; i++){
    ans += min(B[i],B[i+1]) ;
  }
  ans += B[n-2] ;
  cout << ans << endl ;
}