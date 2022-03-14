#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

string S ;

int main(){
  cin >> S ;
  string T ;
  int k = S.size() - 2 ;
  string P = to_string(k) ;
  T = S[0] + P + S[S.size() - 1] ;
  cout << T << endl ;
}