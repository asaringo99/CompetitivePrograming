#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define INF (ll)1e8
#define MAX_N (ll)1e8

int n ;

int main(){
  cin >> n ;
  int A[n] ;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      char s ;
      cin >> s ;
      if(s == '1') A[i] = j ;
    }
  }
  int down = n , row = 0 ;
  for(int i = 0 ; i < n ; i++){
    int count = 0 ;
    for(int j = 0 ; j < n ; j++){
      if(s[i][j] == '1') count++ ;
    }

  }
}