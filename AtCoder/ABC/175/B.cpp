#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

int N ;

int main(){
  int count = 0 ;
  cin >> N ;
  int L[N] ;
  for(int i = 0 ; i < N ; i++) cin >> L[i] ;

  for(int i = 0 ; i < N ; i++){
    for(int j = i + 1 ; j < N ; j++){
      if(L[i] == L[j]) continue ;
      for(int k = j + 1 ; k < N ; k++){
        if(L[i] == L[k] || L[j] == L[k]) continue ;
        int len = L[i] + L[j] + L[k] ;
        int max_l = max(L[i],max(L[j],L[k])) ;
        if(len - max_l > max_l) count = count + 1 ;
        //cout << L[i] << " " << L[j] << " " << L[k] << " " << count << endl ;
      }
    }
  }
  cout << count << endl ;
}