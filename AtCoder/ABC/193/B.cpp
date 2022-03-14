#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
  cin >> n ;
  ll ans = INF ;
  for(int i = 0 ; i < n ; i++){
    ll a , b , c ;
    cin >> a >> b >> c ;
    if(a < c) ans = min(ans,b) ;
  }
  if(ans == INF) ans = -1 ;
  cout << ans << endl ;
}