#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;

double n ;
int k ;

int main(){
  cin >> n >> k ;
  double n1 = 1 / n ;
  double p = 0 ;
  for(int i = 1 ; i <= n ; i++){
    int count = 0 ;
    int val = i ;
    while(val < k){
      count++ ;
      val *= 2 ;
    }
    p += n1 * pow(0.5,count) ;
  }
  cout << setprecision(15) << p << endl ;
}