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

int n , k ;
ll H[101010] , dp[101010] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> H[i] ;
    rep(i,n) dp[i] = 1e12 ;
    dp[0] = 0 ;
    rep(i,n){
        rrep(j,1,k+1) chmin(dp[i+j],dp[i]+abs(H[i+j]-H[i])) ;
    }
    cout << dp[n-1] << endl ;
}