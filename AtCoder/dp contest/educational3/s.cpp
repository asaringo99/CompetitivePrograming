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

int n ;
string S ;
int d ;
ll dp[10101][2][101] ;
vector<int> digit ;

int main(){
    fast_input_output
    cin >> S >> d ;
    n = S.size() ;
    rep(i,n) digit.push_back(S[i] - '0') ;
    dp[0][0][0] = 1 ;
    rep(i,n){
        // 0
        {
            rep(j,d) (dp[i+1][0][(j+digit[i])%d] += dp[i][0][j]) %= mod ;
            rep(j,d) rep(k,digit[i]) (dp[i+1][1][(j+k)%d] += dp[i][0][j]) %= mod ;
        }
        // 1
        {
            rep(j,d) rep(k,10) (dp[i+1][1][(j+k)%d] += dp[i][1][j]) %= mod ;
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << endl ;
}