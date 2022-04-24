#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    ll A[n] , X[n] ;
    memset(X,0,sizeof(X)) ;
    rep(i,n) {
        cin >> A[i] ;
        X[0] += i % 2 == 0 ? A[i] : -A[i] ;
    }
    X[0] /= 2 ;
    for(int i = 1 ; i < n ; i++){
        X[i] = A[i-1] - X[i-1] ;
    }
    rep(i,n) cout << 2 * X[i] << " " ;
    cout << endl ;
}