#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int H , W ;
char S[2020][2020] ;
ll A[2020][2020] , B[2020][2020] , C[2020][2020] ;
ll dp[2020][2020] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    dp[0][0] = 1 ;
    rep(i,H) rep(j,W){
        if(S[i][j] == '#') continue ;
        (dp[i][j+1] += dp[i][j] + A[i][j]) %= mod ;
        (dp[i+1][j] += dp[i][j] + B[i][j]) %= mod ;
        (dp[i+1][j+1] += dp[i][j] + C[i][j]) %= mod ;
        A[i][j+1] = (dp[i][j] + A[i][j]) % mod ;
        B[i+1][j] = (dp[i][j] + B[i][j]) % mod ;
        C[i+1][j+1] = (dp[i][j] + C[i][j]) % mod ;
    }
    cout << dp[H-1][W-1] << endl ;
}