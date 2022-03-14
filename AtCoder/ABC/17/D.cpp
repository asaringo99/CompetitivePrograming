#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , m ;

int f[100007] , pre[100007] ;
ll dp[100007] , S[100007] ; 

int main(){
    memset(pre,-1,sizeof(pre)) ;
    cin >> n >> m ;
    memset(dp,0,sizeof(dp)) ;
    rep(i,n) cin >> f[i] ;
    S[0] = 1 ;
    int val = -1 ;
    for(int i = 1 ; i < n + 1 ; i++){
        val = max(val,pre[f[i-1]]) ;
        if(val == -1) dp[i] = S[i-1] ;
        else dp[i] = (S[i-1] - S[val-1] + mod) % mod ;
        S[i] = (S[i-1] + dp[i]) % mod ;
        pre[f[i-1]] = i ;
    }
    cout << dp[n] << endl ;
}