#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n ;
string S ;
ll dp[101010][13] ;

int main(){
    cin >> S ;
    n = S.size() ;
    dp[0][0] = 1 ;
    rep(i,n){
        rep(j,13){
            if(S[i] == '?'){
                rep(k,10) (dp[i+1][(j*10+k)%13] += dp[i][j]) %= mod ;
            }
            else{
                int v = S[i] - '0' ;
                (dp[i+1][(j*10+v)%13] += dp[i][j]) %= mod ;
            }
        }
    }
    cout << dp[n][5] << endl ;
}