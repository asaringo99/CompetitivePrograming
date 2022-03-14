#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n , k ;
int A[MAX_N] ;

/*
bool cal(int div){
  if(div == 0) return false ;
  int count = 0 ;
  for(int i = 0 ; i < n ; i++){
    if(A[i] % div == 0) count += A[i] / div - 1 ;
    else count += A[i] / div ;
  }
  return count <= k ;
}

int main(){
  cin >> n >> k ;
  for(int i = 0 ; i < n ; i++) cin >> A[i] ;
  int l = 0 , r = 1e9 ;
  while(r - l > 0){
    int m = (l + r) / 2 ;
    if(cal(m)) r = m ;
    else l = m + 1 ;
  }
  cout << r << endl ;
}
*/

bool cal(int x){
    if(x == 0) return false ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++) {
        if(A[i] % x == 0) res += A[i] / x - 1 ;
        else res += A[i] / x ;
    }
    return res <= k ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    int l = 0 , r = (int)1e9 ;
    while(r - l > 0){
        int m = (l + r) / 2 ;
        if(cal(m)) r = m ;
        else l = m + 1 ;
    }
    cout << r << endl ;
}