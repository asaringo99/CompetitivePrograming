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
#define INFO 1000000

int n ;

int main(){
  cin >> n ;
  int A[n] , B[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i < n ; i++) cin >> B[i] ;
  sort(A,A+n) ;
  sort(B,B+n) ;
  int res = 0 ;
  for(int i = 0 ; i < n ; i++) res += A[i] * B[n - 1 - i] ;
  cout << res << endl ;
  cout << sizeof(A) << endl ;
}