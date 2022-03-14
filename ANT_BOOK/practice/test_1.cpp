#include <bits/stdc++.h>
using namespace std ;
using G = vector<int> ;

int main(){
  G A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
  int i,n ;
  cin >> i >> n ;
  for(int j = 0 ; j < n ; j++) A.erase(A.begin()) ;
  cout << A[i] << endl ;
}