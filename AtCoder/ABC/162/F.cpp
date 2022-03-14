#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[202020] ;
ll dp[202020][3] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    if(n % 2 == 0){
        rep(i,n) rep(j,2) dp[i][j] = -1e16 ;
        dp[0][0] = A[0] ;
        dp[1][1] = A[1] ;
        rrep(i,2,n){
            dp[i][0] = max(dp[i][0],dp[i-2][0]+A[i]) ;
            dp[i][1] = max(dp[i][1],dp[i-2][1]+A[i]) ;
            if(i > 2){
                dp[i][1] = max(dp[i][1],dp[i-3][0]+A[i]) ;
            }
        }
        ll res = max({dp[n-2][0],dp[n-1][1]}) ;
        cout << res << endl ;
        return 0 ;
    }
    rep(i,n) rep(j,3) dp[i][j] = -1e16 ;
    dp[0][0] = A[0] ;
    dp[1][1] = A[1] ;
    dp[2][2] = A[2] ;
    rrep(i,2,n){
        dp[i][0] = max(dp[i][0],dp[i-2][0]+A[i]) ;
        dp[i][1] = max(dp[i][1],dp[i-2][1]+A[i]) ;
        dp[i][2] = max(dp[i][2],dp[i-2][2]+A[i]) ;
        if(i > 2){
            dp[i][1] = max(dp[i][1],dp[i-3][0]+A[i]) ;
            dp[i][2] = max(dp[i][2],dp[i-3][1]+A[i]) ;
        }
        if(i > 3) {
            dp[i][2] = max(dp[i][2],dp[i-4][0]+A[i]) ;
        }
    }
    ll res = max({dp[n-3][0],dp[n-2][1],dp[n-1][2]}) ;
    cout << res << endl ;
}