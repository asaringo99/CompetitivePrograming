#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int x , y ;

int main(){
  cin >> x >> y ;
  if(x > y){
    y += 3 ;
    if(y > x) cout << "Yes" << endl ;
    else cout << "No" << endl ;
  }
  else{
    x += 3 ;
    if(x > y) cout << "Yes" << endl ;
    else cout << "No" << endl ;
  }
}