#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 2000
#define INF (ll)1e16
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int mod = 1000000007 ;

int H , W ;
char S[MAX_N][MAX_N] ;
ll dp[MAX_N][MAX_N] ;
ll DS[MAX_N][MAX_N] ;
ll DX[MAX_N][MAX_N] ;
ll DY[MAX_N][MAX_N] ;

void bfs(){
    memset(dp,0,sizeof(dp)) ;
    memset(DX,0,sizeof(DX)) ;
    memset(DY,0,sizeof(DY)) ;
    memset(DS,0,sizeof(DS)) ;
    dp[0][0] = 1 ;
    DX[0][0] = 1 ;
    DY[0][0] = 1 ;
    DS[0][0] = 1 ;
    rep(x,H) rep(y,W) {
        if(x == 0 && y == 0) continue ;
        if(S[x][y] == '#') continue ;
        if(0 <= x - 1) dp[x][y] += DX[x-1][y] ;
        if(0 <= y - 1) dp[x][y] += DY[x][y-1] ;
        if(0 <= x - 1 && 0 <= y - 1) dp[x][y] += DS[x-1][y-1] ;
        dp[x][y] %= mod ;
        DX[x][y] = dp[x][y] ;
        DY[x][y] = dp[x][y] ;
        DS[x][y] = dp[x][y] ;
        if(0 <= x - 1) DX[x][y] += DX[x-1][y] ;
        if(0 <= y - 1) DY[x][y] += DY[x][y-1] ;
        if(0 <= x - 1 && 0 <= y - 1) DS[x][y] += DS[x-1][y-1] ;
        DX[x][y] %= mod ;
        DY[x][y] %= mod ;
        DS[x][y] %= mod ;
    }
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    bfs() ;
    ll ans = dp[H-1][W-1] ;
    cout << ans << endl ;
}