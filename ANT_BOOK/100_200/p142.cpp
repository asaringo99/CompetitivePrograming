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
#define INF 20

int main(){
  int n ;
  cin >> n ;
  for(int i = 0 ; i < 1 << n ; i++){
    cout << i << " " << bitset<8>(i) << endl ;
    for(int j = 0 ; j < n ; j++){
      cout << bitset<5>(i >> j & 1) << endl ;
    }
  }
}