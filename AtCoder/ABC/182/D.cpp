#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int A[n] ;
  ll ide = 0 , stc = 0 , fir = 0 , sec = 0 , maxpath = 0 ;
  ll max_ = 0 ;
  for(int i = 0 ; i < n ; i++){
    cin >> A[i] ;
    stc += A[i] ;
    sec = fir + stc ;
    ide = fir + max_ ;
    maxpath = max(maxpath,max(sec,ide)) ;
    if(ide < sec){
      max_ = stc ;
    }
    fir = sec ;
  }
  cout << maxpath << endl ;
}