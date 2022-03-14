#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;

ll mod = 1e9 + 7 ;

ll cal(ll x , ll n){
  ll res = 1 ;
  while(n > 0){
    if(n & 1) res = (res * x) % mod ;
    x = (x * x) % mod ;
    n >>= 1 ;
  }
}

int main(){
  int n ;
  cin >> n ;
  cout << (10,n) - (8,n) << endl ;
}