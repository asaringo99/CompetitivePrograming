#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define N 100005

ll man ;
double you ;
ll che = 0 ;

int n ;
ll a[N] ;

int main(){
  ll Y = 0 ;
  cin >> n ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  for(int i = 0 ; i < n ; i++){
    Y += a[i] * a[i] ;
    a[i] = abs(a[i]) ;
    man += a[i] ;
    if(a[i] > che) che = a[i] ;
  }
  you = sqrt(Y) ;
  cout << man << endl ;
  cout << setprecision(20) << you << endl ;
  cout << che << endl ;
}