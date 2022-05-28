#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n , k ;
string S ;
ll dp[303][303][303] ;

int main(){
    fast_input_output
    cin >> n >> k >> S ;
    dp[0][0][0] = 1 ;
    rep(i,n) rep(j,k+1) rep(x,j+1) {
        if(S[i] != '0'){
            if(x == j) (dp[i+1][j+1][x+1] += dp[i][j][x]) %= mod ;
            else (dp[i+1][j][x+1] += dp[i][j][x]) %= mod ;
        }
        if(S[i] != '1'){
            if(x == 0) (dp[i+1][j+1][x] += dp[i][j][x]) %= mod ;
            else (dp[i+1][j][x-1] += dp[i][j][x]) %= mod ;
        }
    }
    ll res = 0 ;
    rep(i,k+1) rep(j,i+1) (res += dp[n][i][j]) %= mod ;
    cout << res << endl ;
}