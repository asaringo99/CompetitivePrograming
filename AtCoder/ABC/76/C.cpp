#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

string S , T ;

int main(){
  cin >> S >> T ;

  int index = -1 ;
  for(int i = 0 ; i < S.size() - T.size() + 1 ; i++){
    bool ok = true ;
    for(int j = 0 ; j < T.size() ; j++){
      if(S[i+j] == '?') continue ;
      if(S[i+j] != T[j]) ok = false ;
    }
    if(ok) index = i ;
  }

  if(index == -1){
    cout << "UNRESTORABLE" << endl ;
    return 0 ;
  }

  int i = 0 ;
  string res = "" ; 
  while(i < S.size()){
    if(i == index){
      res += T ;
      i += T.size() ;
    }
    else{
      if(S[i] == '?') res += 'a' ;
      else res += S[i] ;
      i++ ;
    }
  }
  cout << res << endl ;
}