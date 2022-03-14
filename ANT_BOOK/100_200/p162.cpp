#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e5+7

int n ;
int bit[MAX_N + 1] ;

int sum(int i){
  int res = 0 ;
  while(i > 0){
    res += bit[i] ;
    i -= i & -i ;
  }
  return res ;
}

void add(int i , int x){
  while(i <= n){
    bit[i] += x ;
    i += i & -i ;
  }
}

int main(){
  cin >> n ;
  int A[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i <= n ; i++) bit[i] = 0 ;

  int count = 0 ;
  for(int i = 0 ; i < n ; i++){
    count += (i - sum(A[i])) ;
    add(A[i] , 1) ;
  }
  cout << count << endl ;
}