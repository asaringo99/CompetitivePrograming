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

const int mod = 1000000007 ;
ll dp[101][4][4][4] ;

// A : 0 , G : 1 , C : 2 , T : 3

int main(){
    cin >> n ;
    memset(dp,0,sizeof(dp)) ;
    rep(x,4) rep(y,4) rep(z,4){
        if(x == 2 && y == 0 && z == 1) continue ;
        if(x == 1 && y == 0 && z == 2) continue ;
        if(x == 2 && y == 1 && z == 0) continue ;
        dp[3][y][z][x] = 1 ;
    }
    for(int i = 4 ; i < n + 1 ; i++) rep(a,4) rep(x,4) rep(y,4) rep(z,4) {
        if(a == 2 && y == 0 && z == 1) continue ;
        if(a == 1 && y == 0 && z == 2) continue ;
        if(a == 2 && y == 1 && z == 0) continue ;
        if(a == 2 && x == 0 && y == 1) continue ;
        if(a == 2 && x == 0 && z == 1) continue ;
        (dp[i][y][z][a] += dp[i-1][x][y][z]) %= mod ;
    }
    ll sum = 0 ;
    rep(x,4) rep(y,4) rep(z,4){
        (sum += dp[n][x][y][z]) %= mod ;
    }
    cout << sum << endl ;
}