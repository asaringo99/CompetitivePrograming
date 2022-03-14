#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

string S ;

int main(){
  cin >> S ;
  for(int i = 0 ; i < S.size() ; i++){
    if(i % 2 == 0) cout << S[i] ;
  }
  cout << endl ;
}