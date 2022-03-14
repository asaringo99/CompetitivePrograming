#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;

int n , s ;
ll dp[3030][3030][2] , A[3030] ;

int main(){
    cin >> n >> s ;
    rep(i,n) cin >> A[i] ;
    dp[0][0][0] = 1 ;
    rep(i,n) rep(j,s+1){
        if(j == 0) dp[i+1][j][0] = (dp[i][j][0] + 1) % mod ;
        else{
            (dp[i+1][j][0] += dp[i][j][0]) %= mod ;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod ;
        }
        if(j + A[i] <= s){
            (dp[i+1][j+A[i]][0] += dp[i][j][0]) %= mod ;
            (dp[i+1][j+A[i]][1] += dp[i][j][0]) %= mod ;
        }
    }
    cout << dp[n][s][1] << endl ;
}