#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , k ;
ll dp[55][55][2505] ;

int main(){
    cin >> n >> k ;
    dp[0][0][0] = 1 ;
    rep(i,n) rep(j,i+1) rep(p,k+1){
        (dp[i+1][j+2][p+2*(i-j)] += dp[i][j][p] * (i-j) % mod * (i-j) % mod) %= mod ;
        (dp[i+1][j+1][p+2*(i-j)] += dp[i][j][p] * (i-j) % mod * 2 % mod) %= mod ;
        (dp[i+1][j+1][p+2*(i-j)] += dp[i][j][p]) %= mod ;
        (dp[i+1][j][p+2*(i-j)] += dp[i][j][p]) %= mod ;
    }
    cout << dp[n][n][k] << endl ;
}