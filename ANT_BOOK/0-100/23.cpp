#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n , l ;

int main(){
  cin >> n >> l ;
  int x[n] ;
  for(int i = 0 ; i < n ; i++) cin >> x[i] ;
  sort(x,x+n) ;
  
  int L = l / 2 ;
  int max = 0 , min = l + 1 ;
}