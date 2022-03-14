#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int V , T , S , D ;

int main(){
  cin >> V >> T >> S >> D ;
  int d1 = V * T , d2 = V * S ;
  if(d1 <= D && D <= d2) cout << "No" << endl ;
  else cout << "Yes" << endl ;
}