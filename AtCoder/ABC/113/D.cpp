#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int H , W , K ;
const int mod = 1000000007 ;

int main(){
    cin >> H >> W >> K ;
    ll dp[H+1][W] ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 1 ; i < H + 1 ; i++){
        for(int j = 0 ; j < W ; j++){
            for(int S = 0 ; S < 1 << (W - 1) ; S++){
                bool used[W - 1] ;
                memset(used,0,sizeof(used)) ;
                for(int k = 0 ; k < W - 1 ; k++){
                    if(S >> k & 1) used[k] = true ;
                }
                bool ok = true ;
                for(int k = 0 ; k < W - 2 ; k++){
                    if(used[k] && used[k+1]) ok = false ;
                }
                if(!ok) continue ;
                if(j > 0 && used[j-1]){
                    dp[i][j] += dp[i-1][j-1] ;
                }
                if(j < W - 1 && used[j]){
                    dp[i][j] += dp[i-1][j+1] ;
                }
                bool lef = j == 0 ? 0 : used[j-1] ;
                bool rig = j == W - 1 ? 0 : used[j] ;
                if(!lef && !rig){
                    dp[i][j] += dp[i-1][j] ;
                }
                dp[i][j] %= mod ;
            }
        }
    }
    cout << dp[H][K-1] % mod << endl ;
}