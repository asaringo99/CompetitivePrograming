#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

const int digit[9] = {2,5,5,4,5,6,3,7,6} ;
int dp[11][10007] ;

int main(){
    cin >> n >> m ;
    int use[m] ;
    for(int i = 0 ; i < m ; i++) cin >> use[i] ;
    sort(use,use+m) ;
    memset(dp,-1,sizeof(dp)) ;
    dp[0][0] = 0 ;
    for(int i = 0 ; i < m ; i++){
        int req = digit[use[i] - 1] ;
        for(int j = 0 ; j < n + 1 ; j++){
            if(dp[i][j] >= 0) dp[i+1][j] = max(dp[i][j],dp[i+1][j]) ;
            if(dp[i+1][j] >= 0){
                int k = j + req > n ? n + 1 : j + req ;
                dp[i+1][k] = dp[i+1][j] + 1 ;
            }
        }
    }
    int st = -1 , tmp = 0 ;
    for(int i = m ; i > 0 ; i--){
        if(tmp < dp[i][n]){
            tmp = dp[i][n] ;
            st = i ;
        }
    }
    vector<int> res ;
    int col = n ;
    for(int i = st ; i > 0 ; i--){
        int req = digit[use[i - 1] - 1] ;
        while(col - req >= 0 && dp[i][col] == dp[i][col - req] + 1){
            res.push_back(use[i-1]) ;
            col -= req ;
        }
    }
    for(int i = 0 ; i < res.size() ; i++) cout << res[i] ;
    cout << endl ;
}