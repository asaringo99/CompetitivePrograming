#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N 12
#define mod (ll)(1e9+7)

string S ;

int main(){
  map<char,int> cnt ;
  cin >> S ;
  if(S.size() == 1){
    if((S[0] - '0') % 8 == 0) cout << "Yes" << endl ;
    else cout << "No" << endl ;
    return 0 ;
  }
  if(S.size() == 2){
    if(((S[0] - '0') * 10 + (S[1] - '0')) % 8 == 0 || ((S[1] - '0') * 10 + (S[0] - '0')) % 8 == 0) cout << "Yes" << endl ;
    else cout << "No" << endl ;
    return 0 ;
  }
  for(int i = 0 ; i < S.size() ; i++) cnt[S[i]]++ ;
  bool ok = false ;
  for(int i = 104 ; i <= 1000 ; i += 8){
    bool D = true ;
    vector<int> num(10,0) ;
    string T = to_string(i) ;
    for(char u : T) num[u - '0']++ ;
    for(int i = 0 ; i < 10 ; i++){
      if(num[i] == 0) continue ;
      if(cnt['0' + i] < num[i]) D = false ;
    }
    if(D) ok = true ;
  }
  if(ok) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}