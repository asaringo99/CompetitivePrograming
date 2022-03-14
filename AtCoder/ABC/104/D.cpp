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

string S ;

const int MOD = 1000000007 ;

int main(){
    cin >> S ;
    int n = S.size() ;
    ll dp[n+1][4] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(S[i] == '?') dp[i+1][j] += dp[i][j] * 3 ;
            else dp[i+1][j] += dp[i][j] ;

        }
        if(S[i] == 'A' || S[i] == '?') dp[i+1][1] += dp[i][0] ;
        if(S[i] == 'B' || S[i] == '?') dp[i+1][2] += dp[i][1] ;
        if(S[i] == 'C' || S[i] == '?') dp[i+1][3] += dp[i][2] ;
        dp[i+1][0] %= MOD ;
        dp[i+1][1] %= MOD ;
        dp[i+1][2] %= MOD ;
        dp[i+1][3] %= MOD ;
    }
    cout << dp[n][3] << endl ;
}