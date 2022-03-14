#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
vector<int> G[202020] ;
ll dp[202020] , parent[202020] ;
ll fac[202020] , inv[202020] ;
ll res[202020] ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void init(){
    fac[0] = fac[1] = 1 ;
    inv[0] = inv[1] = 1 ;
    rrep(i,2,202020){
        fac[i] = (fac[i-1] * i) % mod ;
        inv[i] = ((inv[i-1]) * powmod(i,mod-2)) % mod ;
    }
}

void dfs(int v , int prev){
    if(v != 0 && G[v].size() == 1){
        dp[v] = 1 ;
        parent[v] = 1 ;
        return ;
    }
    ll res = 0 , pr = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        res += parent[u] ;
        (pr *= inv[parent[u]]) %= mod ;
        (pr *= dp[u]) %= mod ;
    }
    dp[v] = (fac[res] * pr) % mod ;
    parent[v] = res + 1 ;
    return ;
}

void rec(int v , int prev){
    if(prev == -1){
        res[v] = dp[v] ;
    }
    else{
        res[v] = dp[v] * inv[parent[v]-1] % mod * fac[n-1] % mod * inv[n-parent[v]] % mod ;
        ll predp = res[prev] * powmod(dp[v],mod-2) % mod * fac[parent[v]] % mod * fac[n-1-parent[v]] % mod * inv[n-1] % mod ;
        (res[v] *= predp) %= mod ;
    }
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        rec(u,v) ;
    }
}

int main(){
    init() ;
    cin >> n ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    rec(0,-1) ;
    rep(i,n) cout << res[i] << endl ;
}