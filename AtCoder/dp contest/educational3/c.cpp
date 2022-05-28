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

int n ;
ll A[101010][3] ;
ll dp[101010][10] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i][0] >> A[i][1] >> A[i][2] ;
    rep(i,n){
        rep(j,3){
            chmax(dp[i+1][(j+1)%3],dp[i][j]+A[i][j]) ;
            chmax(dp[i+1][(j+2)%3],dp[i][j]+A[i][j]) ;
        }
    }
    cout << max({dp[n][0],dp[n][1],dp[n][2]}) << endl ;
}