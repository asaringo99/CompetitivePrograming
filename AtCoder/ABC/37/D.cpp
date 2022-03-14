#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
const int dx[4] = {-1,1,0,0} , dy[4] = {0,0,1,-1} ;

int H , W ;
int A[1010][1010] ;
ll dp[1010][1010] ;

void dfs(int x , int y){
    if(dp[x][y] != -1) return ;
    ll res = 1 ;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i] , ny = y + dy[i] ;
        if(0 > nx || nx >= H || 0 > ny || ny >= W || A[nx][ny] <= A[x][y]) continue ;
        dfs(nx,ny) ;
        (res += dp[nx][ny]) %= mod ;
    }
    dp[x][y] = res ;
}

int main(){
    memset(dp,-1,sizeof(dp)) ;
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> A[i][j] ;
    rep(i,H) rep(j,W) dfs(i,j) ;
    ll res = 0 ;
    rep(i,H) rep(j,W) (res += dp[i][j]) %= mod ;
    cout << res << endl ;
}