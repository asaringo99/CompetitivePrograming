#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

string S ;
ll dp[100007][13] ;

const int mod = 1000000007 ;

int main(){
    cin >> S ;
    int n = S.size() ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 13 ; j++){
            if(S[i-1] == '?'){
                for(int k = 0 ; k < 10 ; k++){
                    (dp[i][(j * 10 + k) % 13] += dp[i-1][j]) %= mod ;
                }
            }
            else{
                int s = S[i-1] - '0' ;
                (dp[i][(j * 10 + s) % 13] += dp[i-1][j]) %= mod ;
            }
        }
    }
    cout << dp[n][5] << endl ;
}