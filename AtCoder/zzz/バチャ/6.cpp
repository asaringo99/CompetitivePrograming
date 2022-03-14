#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;

ll a , b , c , d ;
ll dp[3030][3030] ;
ll S[3030][3030] ;

int main(){
    cin >> a >> b >> c >> d ;
    dp[a][b] = 1 ;
    rrep(i,a,c+1) rrep(j,b,d+1){
        dp[i][j] += (dp[i-1][j] + dp[i][j-1] * i) % mod ;
        dp[i][j] %= mod ;
    }
    cout << dp[c][d] << endl ;
}