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
#define INF 1000000

int n , k ;
int A[INF] ;

int solve(){
  int ar = n - 1 , al = 0 ;
  sort(A,A+n) ;
  int mean ;
  while(ar - al > 0){
    mean = (ar + al) / 2 ;
    //cout << al << " " << ar << " " << mean << endl ;
    //if(k == A[mean]) return mean ;
    if(k > A[mean]) al = mean + 1 ;
    if(k <= A[mean]) ar = mean ;
  }
  return al ;
}

int main(){
  cin >> n >> k ;
  for(int i = 0 ; i < n ; i++){
    cin >> A[i] ;
  }
  cout << solve() << endl ;
}