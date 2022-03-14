#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , a ;
int X[100] ;
ll dp[60][2600][60] ;

int main(){
    cin >> n >> a ;
    rep(i,n) cin >> X[i] ;
    dp[0][0][0] = 1 ;
    rep(i,n) rep(j,2501) rep(k,n){
        dp[i+1][j][k] += dp[i][j][k] ;
        dp[i+1][j+X[i]][k+1] += dp[i][j][k] ;
    }
    ll res = 0 ;
    rrep(j,1,2501) rep(k,n+1) if(k * a == j) res += dp[n][j][k] ;
    cout << res << endl ;
}