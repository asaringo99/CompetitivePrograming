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

bool mod_pow(int x , int n){
  int X = x ;
  int mod = n ;
  ll res = 1 ; //答えの部分
  while(n > 0){
    if(n & 1) res = res * x % mod ; //掛けた時の余りと元の余りを掛けた時の余りは一致
    x = x * x % mod ;
    n >>= 1 ;
  }
  return res == X ;
}

int main(){
  cin >> n ;
  for(int i = 2 ; i <= n ; i++){
    if(!sosu(n)) break ;
    if(mod_pow(i,n)){
      cout << "YES" << endl ;
      return 0 ;
    }
  }
  cout << "NO" << endl ;
}