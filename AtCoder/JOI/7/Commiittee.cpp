#include <bits/stdc++.h>
using namespace std ;
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
ll dp[101010] ;
ll d[101010] ;
vector<int> G[101010] ;
ll res = -1e10 ;

void dfs(int v , int prev){
    ll sum = d[v] ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        sum += dp[u] > 0 ? dp[u] : 0 ;
    }
    if(sum > 0) dp[v] = sum ;
    else dp[v] = 0 ;
    chmax(res,sum) ;
}

int main(){
    cin >> n ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        d[i] = b ;
        if(a != 0){
            a-- ;
            G[i].push_back(a) ;
            G[a].push_back(i) ;
        }
    }
    dfs(0,-1) ;
    cout << res << endl ;
}