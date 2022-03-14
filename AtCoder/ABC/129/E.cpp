#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
#define INF (ll)1e19
#define mod (ll)(1e9+7)

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    vector<int> digit ;
    for(int i = 0 ; i < n ; i++) digit.push_back(S[i] - '0') ;
    ll dp[n+1][2] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        { // a + b = 0
            if(digit[i] == 0){
                dp[i+1][0] += dp[i][0] ;
                dp[i+1][1] += dp[i][1] ;
            }
            else{
                dp[i+1][1] += dp[i][0] + dp[i][1] ;
            }
        }
        { // a + b = 1
            if(digit[i] == 0){
                dp[i+1][1] += 2 * dp[i][1] ;
            }
            else{
                dp[i+1][0] += 2 * dp[i][0] ;
                dp[i+1][1] += 2 * dp[i][1] ;
            }
        }
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl ;
}