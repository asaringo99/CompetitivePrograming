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
string L ;
ll dp[101010][2] , S[101010] ;

int main(){
    fast_input_output
    cin >> L ;
    n = L.size() ;
    vector<int> digit ;
    rep(i,n) digit.push_back(L[i]-'0') ;
    ll res = 0 ;
    dp[0][0] = 1 ;
    rep(i,n){
        // 0
        {
            if(digit[i] == 0) dp[i+1][0] = dp[i][0] ;
            if(digit[i] == 1) {
                dp[i+1][0] = 2 * dp[i][0] ;
                dp[i+1][1] = dp[i][0] ;
            }
            dp[i+1][0] %= mod ;
        }
        // 1
        {
            (dp[i+1][1] += 3 * dp[i][1]) %= mod ;
        }
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl ;
}