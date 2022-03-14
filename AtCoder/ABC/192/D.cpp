#include <bits/stdc++.h>
using namespace std ;
//typedef long long ll ;
typedef unsigned long long ll ;
#define INF (ll)1e18

string X ;
ll M ;

bool cal(ll n){
  ll val = 0 ;
  ll res = 0 ;
  for(int i = 0 ; i < X.size() ; i++){
    ll tmp = X[X.size() - 1 - i] - '0' ;
    val += tmp * pow(n,i) ;
    res = pow(n,i) ;
    if(val > M || res + 1 > M) return false ;
  }
  return true ;
}

int main(){
  cin >> X >> M ;
  int d = 0 ;
  for(int i = 0 ; i < X.size() ; i++){
    d = max(d,X[i] - '0') ;
  }
  d++ ;
  ll lef = d , rig = M ;
  if(X.size() > 18) rig = 10 ;
  else rig = pow(10,18 / (X.size() - 1)) ;
  while(rig - lef > 1){
    ll m = (rig + lef) / 2 ;
    if(cal(m)) lef = m ;
    else rig = m ;
    //cout << lef << " " << rig << " " << m << endl ;
  }
  cout << lef - d + 1 << endl ;
}