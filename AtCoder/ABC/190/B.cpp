#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n , s , d ;

int main(){
  cin >> n >> s >> d ;
  bool how = false ;
  for(int i = 0 ; i < n ; i++){
    int x , y ;
    cin >> x >> y ;
    if(x < s && y > d) how = true ;
  }
  if(how) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}