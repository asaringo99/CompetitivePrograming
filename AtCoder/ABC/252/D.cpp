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
ll A[202020] , dp[202020][10] ;
map<ll,ll> mp ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        mp[a]++ ;
    }
    int i = 0 ;
    dp[i][0] = 1 ;
    for(auto it : mp){
        rep(j,4){
            dp[i+1][j] += dp[i][j] ;
            dp[i+1][j+1] += dp[i][j] * it.second ;
        }
        i++ ;
    }
    cout << dp[i][3] << endl ;
}