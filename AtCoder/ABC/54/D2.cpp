#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , s , t ;
int dp[50][500][500] ;
TP A[50] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> n >> s >> t ;
    rep(i,n){
        int a , b , c ;
        cin >> a >> b >> c ;
        A[i] = {a,b,c} ;
    }
    rep(i,n+1) rep(j,450) rep(k,450) dp[i][j][k] = 1e8 ;
    dp[0][0][0] = 0 ;
    rep(i,n){
        int a , b , c ;
        tie(a,b,c) = A[i] ;
        rep(x,410) rep(y,410) {
            dp[i+1][x][y] = min(dp[i+1][x][y],dp[i][x][y]) ;
            dp[i+1][x+a][y+b] = min(dp[i+1][x+a][y+b],dp[i][x][y]+c) ;
        }
    }
    int res = 1e8 ;
    rep(j,420) rep(k,420) if(j != 0 && k != 0 && j / gcd(j,k) == s && k / gcd(j,k) == t) res = min(res,dp[n][j][k]) ;
    if(res == 1e8) res = -1 ;
    cout << res << endl ;
}