#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e9+7

priority_queue<int,vector<int>,greater<int>> PQ ;
int n ;

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++){
    int s ;
    cin >> s ;
    PQ.push(s) ;
  }
  int res = 0 ;
  while(true){
    int val1 = PQ.top() ;
    PQ.pop() ;
    if(!PQ.size()) break ;
    int val2 = PQ.top() ;
    PQ.pop() ;
    res += val1 + val2 ;
    PQ.push(res) ;
  }
  cout << res << endl ;
}