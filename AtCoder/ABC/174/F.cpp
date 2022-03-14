#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define MAX_N (ll)2e5

int N , Q ;

int main(){
  set<int> color ;
  cin >> N >> Q ;
  int c[N] ;
  int pes[N+1] ; pes[0] = 0 ;
  for(int i = 1 ; i <= N ; i++){
    int a ; cin >> a ;
    auto it = color.find(a) ;
    if(it != color.end()){
      cout << i << " -> " << a << " " ;
      pes[i] = pes[i-1] ;
    }
    else pes[i] = pes[i-1] + 1 ;
    color.insert(a) ;
  }
  cout << endl ;
  vector<int> res ;
  for(int i = 0 ; i < Q ; i++){
    int l , r ; cin >> l >> r ;
    res.push_back(pes[r] - pes[l-1]) ;
  }
  for(int u : res) cout << u << endl ;
  //for(int u : color) cout << u << endl ;
}