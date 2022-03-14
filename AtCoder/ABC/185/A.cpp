#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  int A = 1000 ;
  for(int i = 0 ; i < 4 ; i++){
    int a ;
    cin >> a ;
    A = min(A,a) ;
  }
  cout << A << endl ;
}