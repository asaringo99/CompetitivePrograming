#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int w , n , k ;
int A[55] , B[55] ;
ll dp[55][10007][55] ;

int main(){
    cin >> w >> n >> k ;
    rep(i,n) cin >> A[i] >> B[i] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0][k] = 0 ;
    rrep(i,1,n+1){
        rrep(j,0,w+1){
            rrep(l,0,k){
                if(l == k){
                    dp[i][j][l] = dp[i-1][j][l] ;
                    continue ;
                }
                if(j - A[i-1] >= 0) dp[i][j][l] = max(dp[i-1][j-A[i-1]][l+1]+B[i-1],dp[i-1][j][l]) ;
                else dp[i][j][l] = dp[i-1][j][l] ;
            }
        }
    }
    ll res = -1 ;
    rep(i,k+1) res = max(res,dp[n][w][i]) ;
    cout << res << endl ;
}