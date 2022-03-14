#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define MAX_N 17

int n ;
int d[MAX_N][MAX_N] ;
int dp[(1 << MAX_N)][MAX_N] ;

int rec(int S , int v){
    if(S == (1 << n) - 1 && v == 0) return dp[S][v] = 0 ;

    if(dp[S][v] >= 0) return dp[S][v] ;

    int res = 1000000000 ;
    for(int i = 0 ; i < n ; i++){
        if(!(S >> i & 1)){
            res = min(res,rec(S | (1 << i) , i) + d[v][i]) ;
        }
    }
    return dp[S][v] = res ;
}

int main(){
    cin >> n  ;
    int X[n] , Y[n] , Z[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> X[i] >> Y[i] >> Z[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            d[i][j] = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max(0,Z[j] - Z[i]) ;
            d[j][i] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0,Z[i] - Z[j]) ;
        }
    }
    //for(int i = 0 ; i < n ; i++) d[i][i] = 1000000000 ;
    memset(dp,-1,sizeof(dp)) ;
    cout << rec(0,0) << endl ;
}