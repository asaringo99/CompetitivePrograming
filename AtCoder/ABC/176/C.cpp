#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;

ll n ;

int main(){
  ll ans = 0 ;
  cin >> n ;
  ll a[n] ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  for(int i = 1 ; i < n ; i++){
    if(a[i-1] > a[i]){
      ans = ans + (a[i-1] - a[i]) ;
      a[i] = a[i-1] ;
    }
  }
  cout << ans << endl ;
}