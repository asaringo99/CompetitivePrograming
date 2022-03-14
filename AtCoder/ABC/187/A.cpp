#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

string a , b ;

int main(){
  cin >> a >> b ;
  int A = a[0]-'0' + a[1]-'0' + a[2]-'0' ;
  int B = b[0]-'0' + b[1]-'0' + b[2]-'0' ;
  string S = "45463473" ;
  if(A > B) cout << A << endl ;
  else cout << B << endl ;
  cout << stoi(S) - 353454 << endl ;
}