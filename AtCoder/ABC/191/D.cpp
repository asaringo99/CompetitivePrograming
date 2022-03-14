#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005
#define INF (double)1e5

double X , Y , R ;

int main(){
  cin >> X >> Y >> R ;
  int lx = (X - R) , rx = (X + R) ;
  ll ans = 0 ;
  for(int x = lx ; x <= rx ; x++){
    ll ly = 0 , ry = INF ;
    while(ry - ly > 0){
      double ym = (ly + ry) / 2 ;
      
      if((ym-Y)*(ym-Y) < R*R - (x-X)*(x-X)) ly = ym + 1 ;
      if((ym-Y)*(ym-Y) >= R*R - (x-X)*(x-X)) ry = ym ;
      cout << " " << ym << " " << Y << " " << ly << " " << ry << " " << (ym-Y)*(ym-Y) << " " << R*R - (x-X)*(x-X) << endl ;
    }
    ll y1 , y2 ;
    if(ry >= Y){
      y1 = ry ;
      y2 = Y - (ry - Y) ;
    }
    else{
      y1 = Y + (Y - ry) ;
      y2 = ry ;
    }
    cout << y1 << " " << y2 << endl ;
    ans += y1 - y2 + 1 ;
  }
  cout << ans << endl ;
}