#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n , k ;

int main(){
  cin >> n >> k ;
  char S[n] ;
  int C[n] ;

  for(int i = 0 ; i < n ; i++) cin >> S[i] ;
  
  int res = 0 , change = 0 ;
  for(int i = 1 ; i < n ; i++){
    if(S[i-1] == S[i]) res++ ;
    if(S[i-1] != S[i]) change++ ;
  }
  bool odd = true ;
  if(change % 2 == 0) odd = false ;

  if(odd){
    change = change / 2 + 1 ;
    if(change > k) res += 2 * k ;
    else res += 2 * change - 1 ;
  }
  else{
    change = change / 2 ;
    if(change > k) res += 2 * k ;
    else res += 2 * change ;
  }
  cout << res << endl ;
}