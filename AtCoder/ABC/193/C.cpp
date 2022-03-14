#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

ll N ;

int main(){
  cin >> N ;
  set<ll> cnt ;
  for(ll i = 2 ; i * i <= N ; i++){
    for(ll j = 2 ; pow(i,j) <= N ; j++){
      cnt.insert(pow(i,j)) ;
    }
  }
  int count = 0 ;
  for(ll u : cnt) count++ ;
  cout << N - count << endl ;
}