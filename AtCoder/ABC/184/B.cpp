#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define INF 200005

int n , x ;

int main(){
  cin >> n >> x ;
  for(int i = 0 ; i < n ; i++){
    char s ;
    cin >> s ;
    if(s == 'o') x++ ;
    else{
      if(x != 0) x-- ; 
    }
  }
  cout << x << endl ;
}