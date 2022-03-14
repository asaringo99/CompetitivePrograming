#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define chmin(a,b) a = min(a,b)

string N ;
ll dp[1010100][15] ;

int main(){
    rep(i,1010100) rep(j,15) dp[i][j] = 1e15 ;
    cin >> N ;
    int n = N.size() ;
    vector<int> digit ;
    for(int i = n - 1 ; i >= 0 ; i--) digit.push_back(N[i] - '0') ;
    digit.push_back(0) ;
    dp[0][0] = 0 ;
    rep(i,n+1){
        rep(j,11){
            if(j == 10){
                chmin(dp[i+1][10],dp[i][j]+10-digit[i]-1) ;
                chmin(dp[i+1][digit[i]+1],dp[i][j]+digit[i]+1) ;
            }
            else{
                chmin(dp[i+1][10],dp[i][j]+10-digit[i]) ;
                chmin(dp[i+1][digit[i]],dp[i][j]+digit[i]) ;
            }
        }
    }
    ll res = LLONG_MAX ;
    rep(i,11) chmin(res,dp[n+1][i]) ;
    cout << res << endl ;
}