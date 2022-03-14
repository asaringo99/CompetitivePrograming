#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , W ;
ll w[110] , v[110] ;
ll dp[110][10101] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ; 
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return a / gcd(a,b) * b ;
}

int main(){
    cin >> n >> W ;
    rep(i,n) cin >> w[i] >> v[i] ;
    rep(i,n) rrep(j,1,W+1){
        if(j == 0 && w[i] <= W) dp[i+1][w[i]] = v[i] ;
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]) ;
        if(lcm(j,w[i]) <= W) dp[i+1][lcm(j,w[i])] = max(dp[i+1][lcm(j,w[i])],dp[i][j]+v[i]) ;
    }
    ll res = 0 ;
    rep(i,W+1) res = max(res,dp[n][i]) ;
    cout << res << endl ;
}