#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e4
#define MAX_C (ll)1e4

const int ST_SIZE = (1 << 15) - 1 ;

int L[MAX_N] ;
int S[MAX_C] , A[MAX_N] ;

int N , C ;
double ang[ST_SIZE] ;
double vx[ST_SIZE] , vy[ST_SIZE] ;

void init(int k , int l , int r){
  ang[k] = vx[k] = 0.0 ;

  if(r - l == 1) vy[k] == L[l] ;
  else{
    int chl = 2 * k + 1 , chr = 2 * k + 2 ;
    int m = (l + r) / 2 ;
    init(chl,l,m) ;
    init(chr,m,r) ;
    vy[k] = vy[chl] + vy[chr] ;
  }
}

void change(int k , double a , int v , int l , int r){
  if(k <= l) return ;
  else if(k < r){
    int chl = 2 * v + 1 , chr = 2 * v + 2 ;
    int m = (l + r) / 2 ;
    change()
  }
}