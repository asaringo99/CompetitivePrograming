#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    int A[n] ;
    rep(i,n) cin >> A[i] ;
    int dp[n] ;
    memset(dp,-1,sizeof(dp)) ;
    for(int i = 0 ; i < n ; i++){
        auto it = lower_bound(dp,dp+n,A[i]) ;
        it-- ;
        int index = it - dp ;
        dp[index] = A[i] ;
    }
    int res = n ;
    for(int i = 0 ; i < n ; i++){
        if(dp[i] == -1) res-- ;
    }
    cout << res << endl ;
}