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
    char S[n] ;
    int W[n+1] , E[n+1] ;
    W[0] = 0 ;
    E[0] = 0 ;
    for(int i = 0 ; i < n ; i++) cin >> S[i] ;
    for(int i = 0 ; i < n ; i++) {
        if(S[i] == 'W') W[i+1] = W[i] + 1 ;
        else W[i+1] = W[i] ;
    }
    for(int i = 0 ; i < n ; i++) {
        if(S[n-1-i] == 'E') E[i+1] = E[i] + 1 ;
        else E[i+1] = E[i] ;
    }
    int res = INT_MAX ;
    for(int i = 1 ; i <= n ; i++){
        res = min(res,W[i-1] + E[n-i]) ;
    }
    cout << res << endl ;
}