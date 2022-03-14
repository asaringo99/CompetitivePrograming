#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e5+7

const int N = (1 >> 15) ;
int dat[N] , datb[N] ;

void add(int k , int a , int b , int l , int r , int x){
  if(l <= a && b <= r){
    datb[k] += x ;
    return ;
  }
  else{
    int chl = k * 2 + 1 , chr = k * 2 + 2 ;
    add(chl , a , (a + b) / 2 , l , r , x) ;
    add(chr , (a + b) / 2 , b , l , r , x) ;
    dat[k] += x ;
  }
}

int sum(int k , int a , int b , int l , int r){
  if(b < l || r < a) return 0 ;
  if(l <= a && b <= r) return dat[k] ;
  else{
    int chl = k * 2 + 1 , chr = k * 2 + 2 ;
    return sum(chl , a , (a + b) / 2 , l , r) + sum(chl , a , (a + b) / 2 , l , r) ;
  }
}