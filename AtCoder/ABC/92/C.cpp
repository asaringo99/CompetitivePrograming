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
    int A[n+2] , S[n+2] ;
    S[0] = 0 ;
    A[0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i + 1] ;
        S[i + 1] = S[i] + abs(A[i + 1] - A[i]) ;
    }
    A[n+1] = 0 ;
    S[n+1] = S[n] + abs(A[n]) ;
    for(int i = 1 ; i <= n ; i++){
        cout << S[i-1] + S[n+1] - S[i+1] + abs(A[i+1] - A[i-1]) << endl ;
    }
}