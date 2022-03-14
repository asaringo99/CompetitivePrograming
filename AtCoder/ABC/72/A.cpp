#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int x , t ;

int main(){
  cin >> x >> t ;
  if(x <= t) cout << 0 << endl ;
  else cout << x - t << endl ;
}