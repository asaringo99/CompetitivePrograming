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

int h , w ;
int A[101][101] , B[101][101] ;
bool dp[101][101][10101] ;

int main(){
    cin >> h >> w ;
    rep(i,h) rep(j,w) cin >> A[i][j] ;
    rep(i,h) rep(j,w) cin >> B[i][j] ;
    dp[0][0][abs(A[0][0]-B[0][0])] = true ;
    rep(i,h) rep(j,w) rep(k,8500){
        int x = A[i][j] - B[i][j] ;
        if(i > 0 && dp[i-1][j][abs(k-x)]) dp[i][j][k] = true ;
        if(i > 0 && dp[i-1][j][abs(k+x)]) dp[i][j][k] = true ;
        if(j > 0 && dp[i][j-1][abs(k-x)]) dp[i][j][k] = true ;
        if(j > 0 && dp[i][j-1][abs(k+x)]) dp[i][j][k] = true ;
    }
    int res = 1e8 ;
    rep(i,8500) if(dp[h-1][w-1][i]) chmin(res,i) ;
    cout << res << endl ;
}