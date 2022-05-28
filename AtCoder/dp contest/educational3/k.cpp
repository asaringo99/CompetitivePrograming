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
int A[101] ;
int dp[202020] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rrep(i,k+1,202020) dp[i] = 1 ;
    for(int i = k - 1 ; i >= 0 ; i--){
        rep(j,n){
            if(dp[i+A[j]] == 0) dp[i] = 1 ;
        }
    }
    if(dp[0] == 0) cout << "Second" << endl ;
    else cout << "First" << endl ;
}