#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
  cin >> n ;
  int A[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  ll cnt[n] ;
  memset(cnt,0,sizeof(cnt)) ;
  for(int i = 0 ; i < n ; i++){
    while(A[i] % 2 == 0){
      A[i] /= 2 ;
      cnt[i]++ ;
    }
  }
  ll res = INF ;
  for(int i = 0 ; i < n ; i++) res = min(res ,cnt[i]) ;
  cout << res << endl ;
}