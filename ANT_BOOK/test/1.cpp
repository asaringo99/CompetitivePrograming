#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e5+7

int n , s ;

int main(){
  cin >> n >> s ;
  int a[n] ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  int tmp = a[0] , i = 0 , j = 0 , leng = MAX_N ;
  while(j - i >= 0 || j){
    if(s > tmp ){
      j++ ;
      if(j == n) break ;
      tmp += a[j] ;
    }
    else{
      leng = min(leng,j-i+1) ;
      tmp -= a[i] ;
      i++ ;
      if(i == n) break ;
    }
  }
  cout << leng << endl ;
}