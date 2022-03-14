#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

ll k , x , d , ans ;

int main(){
  cin >> x >> k >> d ;
  if(x < 0) x = -1 * x ;
  ll syou = x / d ;
  ll sa = k - syou ;
  if(syou <= k && sa % 2 == 0) ans = x - syou * d ;
  else if(syou <= k && sa % 2 != 0) ans = -1 * (x - d - syou * d) ;
  else if(syou > k) ans =  x - k * d ;
  cout << ans << endl ;
}