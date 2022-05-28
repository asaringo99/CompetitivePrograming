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
ll dp[101010] ;
ll H[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> H[i] ;
    rep(i,n) dp[i] = 1e12 ;
    dp[0] = 0 ;
    rep(i,n){
        chmin(dp[i+1],dp[i]+abs(H[i+1]-H[i])) ;
        chmin(dp[i+2],dp[i]+abs(H[i+2]-H[i])) ;
    }
    cout << dp[n-1] << endl ;
}