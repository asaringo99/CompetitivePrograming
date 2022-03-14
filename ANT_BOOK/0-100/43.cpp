#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e9+7

int n ;
vector<pair<int,int>> P ;

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++){
    pair<int,int> pir ;
    cin >> pir.second >> pir.first ;
    P.push_back(pir) ;
  }
  sort(P.begin(),P.end()) ;
  int fir = 0 , cnt = 0 ;
  for(int i = 0 ; i < n ; i++){
    if(fir <= P[i].second){
      cnt++ ;
      fir = P[i].first ;
    }
  }
  cout << cnt << endl ;
}