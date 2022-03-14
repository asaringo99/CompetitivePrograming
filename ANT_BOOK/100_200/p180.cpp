#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
using vec = vector<ll> ;
using mat = vector<vec> ;
#define MAX_N (ll)1e4
#define MAX_C (ll)1e4
#define mod 10000

ll n ;

mat mul(mat A , mat B){
  mat C(A.size() , vec(B[0].size())) ;
  for(int i = 0 ; i < A.size() ; i++){
    for(int j = 0 ; j < B.size() ; j++){
      for(int k = 0 ; k < B[0].size() ; k++){
        C[i][k] += (A[i][j] * B[j][k]) % mod ;
        C[i][k] %= mod ;
      }
    }
  }
  return C ;
}

mat powmul(mat A , mat B , int n){
  while(n > 0){
    if(n & 1) B = mul(A,B) ;
    A = mul(A,A) ;
    n = n >> 1 ;
  }
  return B ;
}

int main(){
  cin >> n ;
  mat A(2,vec(2)) ;
  mat B(2,vec(1)) ;
  A[0][0] = 1 ;
  A[0][1] = 1 ;
  A[1][0] = 1 ;
  A[1][1] = 0 ;
  B[0][0] = 1 ;
  B[1][0] = 1 ;
  for(int i = 0 ; i < n ; i++){
    mat V = powmul(A,B,i-2) ;
    cout << V[0][0] << endl ;
  }

}