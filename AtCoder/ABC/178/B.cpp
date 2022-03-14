#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;

int main(){
  ll a , b , c , d ;
  ll ans[4] ;
  cin >> a >> b >> c >> d ;
  ans[0] = a * c ;
  ans[1] = a * d ;
  ans[2] = b * c ;
  ans[3] = b * d ;
  sort(ans,ans+4) ;
  cout << ans[3] << endl ;
}