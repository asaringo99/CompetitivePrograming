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
ll X[1010] , L[1010] ;
map<ll,ll> dp[1010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> X[i] >> L[i] ;
    dp[0][-101010] = 1 ;
    rrep(i,1,n+1){
        unordered_map<ll,ll> S ;
        int lastval = -10101010 ;
        for(auto it : dp[i-1]){
            lastval = it.first ;
            (S[lastval] += S[lastval-1] + it.second) %= mod ;
        }
        ll x = X[i-1] , p = L[i-1] ;
        rrep(j,x-p,x+p+1){
            if(j > lastval) dp[i][j] = S[lastval] ;
            else dp[i][j] = S[j-1] ;
        }
    }
    ll res = 0 ;
    for(auto it : dp[n]) (res += it.second) %= mod ;
    cout << res << endl ;
}