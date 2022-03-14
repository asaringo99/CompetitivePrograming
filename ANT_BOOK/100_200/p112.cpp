#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 5000
#define INFO 1000000

int n ;
bool prime[MAX_N] ;

int sieve(int n){
  fill(prime,prime+n+1,true) ;
  prime[0] = prime[1] = true ;
  prime[2] = true ;
  for(int i = 2 ; i <= n ; i++){
    if(prime[i]){
      for(int j = 2 ; i * j <= n ; j++) prime[i * j] = false ; 
    }
  }
  int count = 0 ;
  for(int i = 1 ; i <= n ; i++){
    if(prime[i]) count++ ;
  }
  return count ;
}

int main(){
  cin >> n ;
  cout << sieve(n) << endl ;
}