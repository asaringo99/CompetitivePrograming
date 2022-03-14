#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  map<string,int> P ;
  string A[n] ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  for(int i = 0 ; i < n ; i++){
    string S = A[i] ;
    if(S[0] == '!'){
      string T = S.substr(1,S.size()-1) ;
      if(P[T]> 0){
        cout << T << endl ;
        return 0 ;
      }
    }
    else{
      string w = "!" ;
      if(P[w+S] > 0){
        cout << S << endl ;
        return 0 ;
      }
    }
    P[S]++ ;
  }
  cout << "satisfiable" << endl ;
}