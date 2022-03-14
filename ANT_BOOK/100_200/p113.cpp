#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 1000000000000
#define INFO 1000000

ll a , b ;
bool prime[MAX_N] ;

int sieve(ll n , ll n2){
  fill(prime,prime+n+1,true) ;
  prime[0] = prime[1] = true ;
  prime[2] = true ;
  for(int i = 2 ; i <= n ; i++){
    if(prime[i]){
      for(int j = 2 ; i * j <= n ; j++) prime[i * j] = false ; 
    }
  }
  ll count = 0 ;
  ll acount ;
  for(ll i = 1 ; i <= n ; i++){
    if(prime[i]) count++ ;
    if(i == n2) acount = count ;
  }
  return count - acount ;
}

int main(){
  cin >> a , b ;
  cout << sieve(b,a) << endl ;
}