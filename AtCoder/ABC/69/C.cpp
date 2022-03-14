#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
  cin >> n ;
  int A[n] ;
  int cnt2 = 0 , cnt4 = 0 ;
  for(int i = 0 ; i < n ; i++){
    int s ;
    cin >> s ;
    if(s % 4 == 0) cnt4++ ;
    else if(s % 2 == 0) cnt2++ ;
  }
  int oth = n - cnt4 - cnt2 ;
  if(oth + cnt4 == n && oth <= cnt4 + 1) cout << "Yes" << endl ;
  else if(cnt4 >= oth) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}