#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_M (ll)100
#define MAX_N 16
#define INF (ll)1e18

int n ;

int main(){
  cin >> n ;
  ll A[n] , B[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] >> B[i] ;

  ll res = INF ;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      ll tmp = 0 ;
      for(int k = 0 ; k < n ; k++){
        tmp += abs(A[i] - A[k]) + abs(A[k] - B[k]) + abs(B[k] - B[j]) ;
      }
      res = min(res,tmp) ;
    }
  }
  cout << res << endl ;
}