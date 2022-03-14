#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

string S ;

int main(){
  cin >> S ;
  int count = 0 ;
  for(int i = 0 ; i < 3 ; i++){
    if(S[i] == '1') count++ ;
  }
  cout << count << endl ;
}