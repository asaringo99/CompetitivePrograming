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

int n , x ;

int gcd(int a , int b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> n >> x ;
    int X[n+1] ;
    X[0] = x ;
    for(int i = 1 ; i < n + 1 ; i++) cin >> X[i] ;
    sort(X,X+n+1) ;

    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        res = gcd(res,X[i+1]-X[i]) ;
    }
    cout << res << endl ;
}