#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

ll n ;

int main(){
  cin >> n ;
  ll ans ;
  for(int i = 0 ; i * i <= n ; i++){
    ans = i * i ;
  }
  cout << ans << endl ;
}