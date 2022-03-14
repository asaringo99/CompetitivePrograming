#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n ;
vector<int> G[202020] ;
int dp[202020] ;
int prevv[202020] ;

void dfs(int v , int prev){
    int res = 1 ;
    prevv[v] = prev ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        res += dp[u] ;
    }
    dp[v] = res ;
}

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    ll res = 0 ;
    rep(v,n){
        if(G[v].size() == 1) continue ;
        ll w = 1 , cnt = 0 ;
        for(int u : G[v]){
            if(prevv[v] == u) continue ;
            (w += powmod(2,dp[u]) - 1) %= mod ;
            cnt += dp[u] ;
        }
        (w += powmod(2,n-cnt-1) - 1) %= mod ;
        (res += powmod(2,n-1) - w + mod) %= mod ;
    }
    (res *= powmod(powmod(2,mod-2),n)) %= mod ;
    cout << res << endl ;
}