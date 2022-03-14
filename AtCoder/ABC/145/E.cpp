#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 3000
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int N , T ;

int main(){
    cin >> N >> T ;
    P A[N] ;
    rep(i,N) cin >> A[i].first >> A[i].second ;
    sort(A,A+N) ;
    int dp[N+1][T+1] ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < T ; j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]) ;
            int ind = min( T, j + A[i].first ) ;
            dp[i+1][ind] = max(dp[i+1][ind],dp[i][j] + A[i].second ) ;
            dp[i+1][ind] = max(dp[i+1][ind],dp[i][ind]) ;
        }
    }
    int res = 0 ;
    for(int i = 0 ; i <= N ; i++){
        res = max(res,dp[i][T]) ;
    }
    cout << res << endl ;
}