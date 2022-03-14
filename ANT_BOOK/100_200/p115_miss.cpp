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

bool sosu(int n){
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0) return true ;
  }
  return false ;
}

bool solve(int n){
  for(int i = 2 ; i < n ; i++){
    ll val = i ;
    for(int j = 2 ; j <= n ; j++){
      val = (val * i) % n ;
    }
    if(i == val) return true ;
  }
  return false ;
}

int main(){
  cin >> n ;
  if(sosu(n) && solve(n)){
    cout << "YES" << endl ;
  }
  else cout << "NO" << endl ;
}