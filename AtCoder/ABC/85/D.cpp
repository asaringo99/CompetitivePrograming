#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n , h ;

int main(){
  cin >> n >> h ;
  pair<ll,ll> katana[n] ;
  ll sord = 0 ;
  for(int i = 0 ; i < n ; i++){
    ll a , b ;
    cin >> a >> b ;
    sord = max(sord,a) ;
    katana[i].first = b ; katana[i].second = a ;
  }
  sort(katana,katana+n,greater<pair<ll,ll>>()) ;
  int ind ;
  for(int i = 0 ; i < n ; i++){
    if(katana[i].first >= sord) ind = i ;
  }
  ll ex = 0 ;
  for(int i = 0 ; i < ind + 1 ; i++){
    h -= katana[i].first ;
    ex++ ;
    if(h <= 0){
      cout << ex << endl ;
      return 0 ;
    }
  }
  if(h % sord == 0) cout << ex + h / sord << endl ;
  else cout << ex + h / sord + 1 << endl ;
}