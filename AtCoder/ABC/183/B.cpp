#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define INF 10007

double sx , sy , gx , gy ;

int main(){
  cin >> sx >> sy >> gx >> gy ;
  gy = - 1 * gy ;
  double a = (gx - sx) / (gy - sy) ;
  double ans = sx - a * sy ;
  cout <<  setprecision(15) << ans << endl ;
}