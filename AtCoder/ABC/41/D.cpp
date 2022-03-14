#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n, m ;
vector<int> Y[20] ;
ll dp[1 << 20][20] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int x , y ;
        cin >> x >> y ;
        x-- ; y-- ;
        Y[y].push_back(x) ;
    }
    rep(i,n) dp[1 << i][i] = 1 ;
    rrep(S,1,1<<n){
        rep(i,n){
            if(!(S >> i & 1)) continue ;
            for(int u : Y[i]) if(!(S >> u & 1)) dp[S][i] = 0 ;
        }
        rep(i,n) rep(j,n) if(!(S >> j & 1)) dp[S | (1 << j)][j] += dp[S][i] ;
    }
    ll res = 0 ;
    rep(i,n) res += dp[(1 << n)-1][i] ;
    cout << res << endl ;
}