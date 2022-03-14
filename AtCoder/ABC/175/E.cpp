#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int R , C , K ;

int main(){
    cin >> R >> C >> K ;
    ll V[R][C] ;
    memset(V,0,sizeof(V)) ;
    for(int i = 0 ; i < K ; i++){
        int r , c , v ;
        cin >> r >> c >> v ;
        r-- ;
        c-- ;
        V[r][c] = v ;
    }
    ll dp[R + 1][C][4] ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 1 ; i <= R ; i++){
        dp[i][0][0] = dp[i-1][0][1] ;
        dp[i][0][1] = dp[i-1][0][1] + V[i-1][0] ;
        for(int j = 1 ; j < C ; j++){
            for(int k = 0 ; k < 4 ; k++){
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][k]) ;
            }
            dp[i][j][1] = max(dp[i][j][0] + V[i-1][j] , dp[i][j-1][1]) ;
            dp[i][j][1] = max(dp[i][j][1] , dp[i][j-1][0] + V[i-1][j]) ;
            for(int k = 2 ; k < 4 ; k++){
                dp[i][j][k] = max( dp[i][j-1][k-1] + V[i-1][j] , dp[i][j-1][k] ) ;
            }
        }
    }
    ll res = 0 ;
    for(int i = 0 ; i < 4 ; i++){
        res = max(res,dp[R][C-1][i]) ;
    }
    cout << res << endl ;
}