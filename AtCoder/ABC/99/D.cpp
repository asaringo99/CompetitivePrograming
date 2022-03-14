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

int n , c ;

int main(){
    cin >> n >> c ;
    int D[c][c] , X[n][n] ;
    for(int i = 0 ; i < c ; i++){
        for(int j = 0 ; j < c ; j++) cin >> D[i][j] ;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++) {
            cin >> X[i][j] ;
            X[i][j]-- ;
        }
    }
    int S[3][c] ;
    memset(S,0,sizeof(S)) ;
    for(int col = 0 ; col < c ; col++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int k = (i + j + 2) % 3 ;
                int x = X[i][j] ;
                S[k][col] += D[x][col] ;
            }
        }
    }
    int res = INT_MAX ;
    for(int i = 0 ; i < c ; i++){
        for(int j = 0 ; j < c ; j++){
            if(i == j) continue ;
            for(int k = 0 ; k < c ; k++){
                if(i == k || j == k) continue ;
                res = min(res,S[0][i]+S[1][j]+S[2][k]) ;
            }
        }
    }
    cout << res << endl ;
}