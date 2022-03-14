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
    int A[n][28] , B[28] ;
    memset(A,0,sizeof(A)) ;
    memset(B,0,sizeof(B)) ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        for(int j = 0 ; j < 28 ; j++){
            if(a >> j & 1) A[i][j]++ ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        int b ;
        cin >> b ;
        for(int j = 0 ; j < 28 ; j++){
            if(b >> j & 1) B[j]++ ;
        }
    }
    int XOR[29] , S[29] ;
    memset(S,0,sizeof(S)) ;
    memset(XOR,0,sizeof(XOR)) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 28 ; j++){
            if(A[i][j] && B[j] > 0) XOR
        }
    }
    for(int i = 0 ; i < 28 ; i++){
        XOR[i] += (n - A[i]) * B[i] + A[i] * (n - B[i]) ;
        S[i+1] = A[i] * B[i] ;
    }
    ll res = 0 ;
    for(int i = 0 ; i < 29 ; i++){
        cout << XOR[i] << " " ;
        if((XOR[i] + S[i]) % 2 == 1) res += pow(2,i) ;
    }
    cout << endl ;
    cout << res << endl ;
}