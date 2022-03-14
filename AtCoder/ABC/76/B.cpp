#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n , k ;

int main(){
  cin >> n >> k ;
  int sum = 1 ;
  for(int i = 0 ; i < n ; i++){
    if(2 * sum <= sum + k) sum *= 2 ;
    else sum += k ;
  }
  cout << sum << endl ;
}