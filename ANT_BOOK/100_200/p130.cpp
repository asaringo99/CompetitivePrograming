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
#define INF 100000007

int n , k ;
int L[INF] ;

float solve(){
  sort(L,L+n) ;
  int lef = 0 , rig = L[0] ;
  int mean ;
  float res ;
  while(rig - lef > 0){
    mean = (lef + rig) / 2 ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
      count += L[i] / mean ;
    }
    if(count == k) res = mean ;
    if(count >= k) lef = mean + 1 ;
    if(count < k) rig = mean ;
  }
  return res ;
}

int main(){
  cin >> n >> k ;
  for(int i = 0 ; i < n ; i++){
    float t ;
    cin >> t ;
    L[i] = t * 100 ;
  }
  cout << solve() / 100 << endl ;
}