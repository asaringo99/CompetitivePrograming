#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
#define MAX_N (ll)2e5
#define MAX_M (ll)1e6

int n ;
int A[MAX_N] ;
bool primenumber[MAX_M+1] ;

void semiprime(){
  fill(primenumber,primenumber+MAX_M+1,true) ;
  int u = -1 ;
  for(int i = 0 ; i < n ; i++){
    if(u == A[i]){
      primenumber[u] = false ;
      continue ;
    }
    u = A[i] ;
    for(int j = 2 * u ; j <= MAX_M ; j += u){
      primenumber[j] = false ;
    }
  }
}

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  sort(A,A+n) ;
  semiprime() ;
  int res = 0 ;
  for(int i = 0 ; i < n ; i++){
    if(primenumber[A[i]]) res++ ;
  }
  cout << res << endl ;
}