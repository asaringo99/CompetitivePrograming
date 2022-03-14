#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n , k ;

int main(){
  cin >> n >> k ;
  double P[n + 1] ;
  P[0] = 0 ;
  for(int i = 1 ; i <= n ; i++){
    int p ;
    cin >> p ;
    P[i] = P[i-1] + (double)(p + 1) / 2 ;
  }
  double sum = 0 , ans = 0 ;
  for(int i = k ; i <= n ; i++){
    ans = max(ans , P[i] - P[i - k]) ;
  }
  cout << setprecision(10) << ans << endl ;
}