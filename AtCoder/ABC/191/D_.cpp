#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005
#define INF (double)1e5

ll X , Y , R ;

int main(){
  cin >> X >> Y >> R ;
  X *= 10000 ; Y *= 10000 ; R *= 10000 ;
  int lx = (X - R) , rx = (X + R) ;
  ll ans = 0 ;
  for(int x = lx ; x <= rx ; x++){
    ll y1 , y2 ;
    if(Y + sqrt(R*R - (x-X)*(x-X)) < 0) y1 = (ll)(Y + sqrt(R*R - (x-X)*(x-X))) - 1 ;
    else if(Y + sqrt(R*R - (x-X)*(x-X)) == (ll)(Y + sqrt(R*R - (x-X)*(x-X)))) y1 = (ll)(Y + sqrt(R*R - (x-X)*(x-X))) ;
    else y1 = (ll)(Y + sqrt(R*R - (x-X)*(x-X))) ;
    if(Y - sqrt(R*R - (x-X)*(x-X)) < 0) y2 = (ll)(Y - sqrt(R*R - (x-X)*(x-X))) ;
    else if(Y - sqrt(R*R - (x-X)*(x-X)) == (ll)(Y - sqrt(R*R - (x-X)*(x-X)))) y2 = (ll)(Y - sqrt(R*R - (x-X)*(x-X))) ;
    else y2 = (ll)(Y - sqrt(R*R - (x-X)*(x-X))) + 1 ;
    ans += y1 - y2 + 1 ;
  }
  cout << ans / 10000 << endl ;
}