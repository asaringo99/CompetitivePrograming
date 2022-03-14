#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

string N ;
int k ;

int main(){
  cin >> N >> k ;
  for(int i = 1 ; i <= k ; i++){
    string g1 = N , g2 = N ;
    sort(g1.begin(),g1.end()) ;
    sort(g2.begin(),g2.end(),greater<char>()) ;
    int v2 = stoi(g2) , v1 = stoi(g1) ;
    int res = v2 - v1 ;
    N = to_string(res) ;
  }
  cout << N << endl ;
}