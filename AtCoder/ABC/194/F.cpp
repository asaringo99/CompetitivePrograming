#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define inf (ll)1e15

string S ;
int k ;

int mod = 1000000007 ;

int main(){
    cin >> S >> k ;
    int n = S.size() ;
    vector<int> digit ;
    for(int i = 0 ; i < n ; i++){
        if(S[i] == 'A') digit.push_back(10) ;
        if(S[i] == 'B') digit.push_back(11) ;
        if(S[i] == 'C') digit.push_back(12) ;
        if(S[i] == 'D') digit.push_back(13) ;
        if(S[i] == 'E') digit.push_back(14) ;
        if(S[i] == 'F') digit.push_back(15) ;
        else digit.push_back(S[i] - '0') ;
    }
    int dp[n+1][2][16] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0][0] = 1 ;
    set<int> kind ;
    for(int i = 0 ; i < n ; i++){
        int index = kind.size() ;
        kind.insert(digit[i]) ;
        dp[i+1][0][kind.size()] = dp[i][0][index] ;
        for(int j = 0 ; j <= 15 ; j++){
            dp[i+1][1][j] = dp[i][0][index] * (16 - index) % mod + dp[i][0][index] * index % mod ;
        }
        for(int j = 0 ; j <= 15 ; j++){
            dp[i+1][1][]
        }
    }
}