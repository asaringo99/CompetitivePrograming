#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n , x ;

int main(){
  cin >> n >> x ;
  vector<int> V ;
  for(int i = 0 ; i < n ; i++){
    int s ;
    cin >> s ;
    if(s != x) V.push_back(s) ;
  }
  for(int u : V) cout << u << " " ;
  cout << endl ;
}