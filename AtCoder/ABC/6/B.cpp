#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  ll a0 = 0 , a1 = 0 , a2 = 1 , an ;
  for(int i = 3 ; i <= n ; i++){
    an = a0 + a1 + a2 ;
    a0 = a1 ;
    a1 = a2 ;
    a2 = an ;
  }
  cout << an << endl ;
}