#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int a , b , c ;

int main(){
  cin >> a >> b >> c ;
  if(c == 0) a-- ;
  if(a >= b) cout << "Takahashi" << endl ;
  else cout << "Aoki" << endl ;
}