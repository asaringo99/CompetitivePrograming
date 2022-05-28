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
ll dp[1 << 21] ;
int A[22][22] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    dp[0] = 1 ;
    rep(i,n) rep(S,1<<n) {
        if(bit_count(S) != i) continue;
        rep(j,n) if(!(S >> j & 1)) if(A[i][j] == 1) (dp[S | 1 << j] += dp[S]) %= mod ;
    }
    cout << dp[(1<<n)-1] << endl ;
}