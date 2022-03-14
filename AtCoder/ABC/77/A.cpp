#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

string S , T ;

int main(){
  cin >> S >> T ;
  if(S[0] == T[2] && S[1] == T[1] && S[2] == T[0]) cout << "YES" << endl ;
  else cout << "NO" << endl ;
}