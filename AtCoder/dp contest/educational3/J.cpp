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

int n ;

ld dp[303][303][303] ;

int main(){
    cin >> n ;
    int a = 0 , b = 0 , c = 0 ;
    rep(i,n){
        int x ;
        cin >> x ;
        if(x == 1) c++ ;
        if(x == 2) b++ ;
        if(x == 3) a++ ;
    }
    dp[0][0][0] = 0 ;
    rep(i,301) rep(j,301) rep(k,301){
        int sum = i + j + k ;
        if(sum == 0) continue ;
        ld c = (ld)n / sum ;
        ld e = c ;
        if(i != 0) e += (ld)i / sum * dp[i-1][j+1][k] ;
        if(j != 0) e += (ld)j / sum * dp[i][j-1][k+1] ;
        if(k != 0) e += (ld)k / sum * dp[i][j][k-1] ;
        dp[i][j][k] = e ;
    }
    cout << fixed << setprecision(25) << dp[a][b][c] << endl ;
}