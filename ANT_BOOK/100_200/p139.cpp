#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 65000
#define INF 5007

int n ;
int A[INF] ;
int f[INF] ;

int solve(int k){
  memset(f,0,sizeof(f)) ;
  int sum = 0 , res = 0 ;
  for(int i = 0 ; i + k <= n ; i++){
    if( (sum + A[i]) % 2 != 0 ){
      res++ ;
      f[i] = 1 ;
    }
    sum += f[i] ;
    if(i - k + 1 >= 0) sum -= f[i - k + 1] ;
  }
  for(int i = n - k + 1 ; i < n ; i++){
    if((sum + A[i]) % 2 != 0) return -1 ;
    if(i - k + 1 >= 0) sum -= f[i - k + 1] ;
  }
  return res ;
}

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++){
    char fb ;
    cin >> fb ;
    if(fb == 'F') A[i] = 0 ;
    else A[i] = 1 ;
  }
  int M = n , K = n ;
  for(int k = 1 ; k < n ; k++){
    if(solve(k) != -1){
      M = min(M,solve(k)) ;
      K = k ;
    }
  }
}