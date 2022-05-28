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
ll A[404] ;
ll dp[404][404] , S[404] ;

ll rec(int x , int y){
    if(x == y) return dp[x][y] = 0 ;
    if(dp[x][y] != -1) return dp[x][y] ;
    ll res = 1e18 , sum = A[y] ;
    rrep(i,x,y){
        sum += A[i] ;
        chmin(res,rec(x,i)+rec(i+1,y)) ;
    }
    return dp[x][y] = res + sum ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n+1) rep(j,n+1) dp[i][j] = -1 ;
    cout << rec(0,n-1) << endl ;
}