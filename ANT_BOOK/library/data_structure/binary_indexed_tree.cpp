#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8

int bit[MAX_N + 1] , n ; //bit[0] = 0

int sum(int i){
  int s = 0 ;
  while(i > 0){
    s += bit[i] ;
    i -= i & -i ; // iから(i & -i)を引く
  }
  return s ;
}

void add(int i , int x){
  while(i <= n){
    bit[i] += x ;
    i += i & -i ;
  }
}

int main(){
  int n ;
  cin >> n ;
  cout << bitset<8>((n&-n)) << endl ;
}