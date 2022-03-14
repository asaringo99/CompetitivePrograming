#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  vector<ll> A(n) , B(n) , C(n) ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i < n ; i++) cin >> B[i] ;
  for(int i = 0 ; i < n ; i++) cin >> C[i] ;
  sort(A.begin() , A.end()) ;
  //sort(B.begin() , B.end()) ;
  sort(C.begin() , C.end()) ;

  ll ans = 0 ;
  for(int i = 0 ; i < n ; i++){
    ll a = lower_bound(A.begin(),A.end(),B[i]) - A.begin() ;
    ll b = upper_bound(C.begin(),C.end(),B[i]) - C.begin() ;
    ans += a * (n - b) ;
  }
  cout << ans << endl ;
}