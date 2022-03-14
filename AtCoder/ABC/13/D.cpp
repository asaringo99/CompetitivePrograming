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

int n , m , d ;
int A[200007] , P[200007] , f[33][200007] ;

void hyperswap(){
    for(int i = 2 ; i < 33 ; i++){
        for(int j = 0 ; j <= n ; j++){
            int to = f[i-1][j] ;
            f[i][j] = f[i-1][to] ;
        }
    }
}

int calculation(int x , int n){
    int k = 1 ;
    while(n > 0){
        if(n & 1) x = f[k][x] ;
        k++ ;
        n >>= 1 ;
    }
    return x + 1 ;
}

int main(){
    cin >> n >> m >> d ;
    for(int i = 0 ; i < n ; i++) P[i] = i ;
    for(int i = 0 ; i < m ; i++) cin >> A[i] ;
    for(int i = 0 ; i < m ; i++){
        int a = A[i] - 1 , b = A[i] ;
        swap(P[a],P[b]) ;
    }
    rep(i,n) f[1][P[i]] = i ;
    hyperswap() ;
    for(int i = 0 ; i < n ; i++){
        cout << calculation(i,d) << endl ;
    }
}