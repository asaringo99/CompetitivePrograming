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
int A[101] ;
ll dp[101][101010] , S[101010] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    dp[0][0] = 1 ;
    rep(i,n) cin >> A[i] ;
    rrep(i,1,n+1) {
        rep(j,k+1) S[j] = j == 0 ? dp[i-1][j] : (S[j-1] + dp[i-1][j]) % mod ;
        rep(j,k+1) dp[i][j] = j - A[i-1] <= 0 ? S[j] : (S[j] - S[j-A[i-1]-1] + mod) % mod ;
    }
    cout << dp[n][k] << endl ;
}