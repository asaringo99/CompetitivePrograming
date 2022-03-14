#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

string S ;
int k ;

int main(){
    cin >> S >> k ;
    vector<int> digit ;
    int N = S.size() ;
    for(int i = 0 ; i < N ; i++) digit.push_back(S[i] - '0') ;
    int dp[N+1][2][k+2] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0][0] = 1 ;
    for(int i = 0 ; i < N ; i++){
        for(int smaller = 0 ; smaller < 2 ; smaller++){
            for(int j = 0 ; j < k + 1 ; j++){
                for(int x = 0 ; x <= (smaller ? 9 : digit[i]) ; x++){
                    if(x != 0) dp[i+1][x < digit[i] || smaller][j+1] += dp[i][smaller][j] ;
                    else dp[i+1][x < digit[i] || smaller][j] += dp[i][smaller][j] ;
                }
            }
        }
    }
    cout << dp[N][0][k] + dp[N][1][k] << endl ;
}