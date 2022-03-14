#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_M (ll)100
#define MAX_N 16
#define INF 1e7

int n , S ;

int main(){
  cin >> n >> S ;
  int a[n] ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  int lef = 0 , rig = 0 , sum = 0 , res = INF ;
  while(rig < n){
    while(sum < S && rig < n){
      sum += a[rig] ;
      rig++ ;
    }
    while(sum >= S){
      res = min(res,rig - lef) ;
      sum -= a[lef] ;
      lef++ ;
    }
  }
  cout << res << endl ;
}