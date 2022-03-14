#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , W ;
unordered_map<ll,ll> dp[110] ;
ll w[110] , v[110] ;

int main(){
    cin >> n >> W ;
    rep(i,n) cin >> w[i] >> v[i] ;
    dp[0][0] = 0 ;
    rep(i,n){
        for(auto it : dp[i]){
            ll j = it.first ;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]) ;
            dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j]+v[i]) ;
        }
    }
    ll res = -1 ;
    for(auto it : dp[n]){
        if(it.first <= W) res = max(res,dp[n][it.first]) ;
    }
    cout << res << endl ;
}