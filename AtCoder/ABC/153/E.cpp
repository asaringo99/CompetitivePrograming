#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int h , n ;
ll dp[1010][10100] ;
ll A[1010] , B[1010] ;

int main(){
    cin >> h >> n ;
    rep(i,n) cin >> A[i] >> B[i] ;
    rep(i,n+1) rep(j,h+1) dp[i][j] = INT_MAX ;
    dp[0][0] = 0 ;
    rrep(i,1,n+1) rep(j,h+1){
        dp[i][j] = min(dp[i][j],dp[i-1][j]) ;
        int k = j + A[i-1] > h ? h : j + A[i-1] ;
        dp[i][k] = min(dp[i][k],dp[i][j]+B[i-1]) ;
    }
    cout << dp[n][h] << endl ;
}