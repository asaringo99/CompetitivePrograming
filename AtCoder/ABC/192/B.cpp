#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

string small = "abcdefghijklmnopqrstuvwxyz" ;
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

string S ;

int main(){
  cin >> S ;
  map<char,bool> ok_up , ok_sm ;
  for(int i = 0 ; i < 26 ; i++){
    ok_sm[small[i]] = true ;
    ok_up[upper[i]] = true ;
  }

  bool ok = true ;
  for(int i = 0 ; i < S.size() ; i++){
    if(i % 2 == 0 && !ok_sm[S[i]]) ok = false ;
    if(i % 2 == 1 && !ok_up[S[i]]) ok = false ;
  }
  if(ok) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}
