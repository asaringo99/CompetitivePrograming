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

bool is_prime(ll n){
  for(ll i = 2 ; i * i <= n ; i++){
    if(n % i == 0) return false ;
  }
  return n != 1 ;
}

vector<ll> divisor(int n){
  vector<ll> divi ;
  for(int i = 1 ; i * i <= n ; i++){
    if(n % i == 0){
      divi.push_back(i) ;
      if(i != n / i) divi.push_back(n / i) ;
    }
  }
  sort(divi.begin(),divi.end()) ;
  return divi ;
}

map<int,int> prime_factor(int n){
  map<int,int> res ;
  for(int i = 2 ; i * i <= n ; i++){
    while(n % i == 0){
      ++res[i] ;
      n /= i ;
    }
  }
  if(n != 1) res[n] = 1 ;
  return res ;
}

int main(){
  ll n ;
  cin >> n ;
  /*
  vector<ll> res = divisor(n) ;
  for(auto u : res) cout << u << endl ;
  */
 map<int,int> res = prime_factor(n) ;
 for(int i = 2 ; i * i <= n ; i++){
   if(res[i] == 0) continue ;
   cout << i << "^" << res[i] << "*" ;
 }
 cout << endl ;
}