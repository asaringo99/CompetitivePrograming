#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
  bool mins = false ;
  cin >> n ;
  int A[n] ;
  int tmp = 0 ;
  int ind ;
  for(int i = 0 ; i < n ; i++){
    cin >> A[i] ;
    if(tmp <= abs(A[i])){
      tmp = abs(A[i]) ;
      if(A[i] < 0) mins = true ;
      else mins = false ;
      ind = i + 1 ;
    }
  }

  if(mins){
    cout << 2 * n << endl ;
    cout << ind << " " << 1 << endl ;
    cout << ind << " " << 1 << endl ;
    for(int i = n - 1 ; i >= 1 ; i--){
      cout << 1 << " " << i << endl ;
      cout << 1 << " " << 1 << endl ;
    }
  }
  else{
    cout << 2 * n << endl ;
    cout << ind << " " << n << endl ;
    cout << ind << " " << n << endl ;
    for(int i = 2 ; i <= n ; i++){
      cout << n << " " << i << endl ;
      cout << n << " " << n << endl ;
    }
  }
}