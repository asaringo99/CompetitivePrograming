#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int main(){
  int n ;
  int ans = 0 ;
  for(int i = 0 ; i < n ; i++){
    int a , b ;
    cin >> a >> b ;
    for(int j = a ; j < b + 1 ; j++) ans = ans + j ;
  }
  cout << ans << endl ;
}