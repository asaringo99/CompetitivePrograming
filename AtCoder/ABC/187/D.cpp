#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  ll d[n] ;
  ll sum_x = 0 ;
  for(int i = 0 ; i < n ; i++){
    ll s , t ;
    cin >> s >> t ;
    sum_x += s ;
    d[i] = 2 * s + t ;
  }
  sort(d,d+n) ;
  ll sum = 0 , count = 0 ;
  for(int i = n - 1 ; i >= 0 ; i--){
    sum += d[i] ;
    count++ ;
    if(sum > sum_x) break ;
  }
  cout << count << endl ;
}