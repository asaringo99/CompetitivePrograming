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
ll A[3030] , S[3030] , M[3030] ;
ll dp[3030][3030] ;

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n+1) cin >> A[i] ;
    dp[0][0] = 1 ;
    rrep(i,1,n+1){
        ll sum = 0 ;
        unordered_map<int,ll> mp ;
        mp[0] = dp[i-1][i-1] ;
        rrep(j,i,n+1){
            sum += A[j] ;
            (dp[i][j] += mp[sum%i]) %= mod ;
            (mp[sum%i] += dp[i-1][j]) %= mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,n+1) (res += dp[i][n]) %= mod ;
    cout << res << endl; 
}