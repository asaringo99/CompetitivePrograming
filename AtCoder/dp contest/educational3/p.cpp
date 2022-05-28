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
vector<int> G[101010] ;
ll dp[101010][2] ;

void dfs(int v , int prev){
    ll b = 1 , w = 1 ;
    for(int u : G[v]){
        if(u == prev) continue;
        dfs(u,v) ;
        b *= dp[u][0] ;
        w *= dp[u][0] + dp[u][1] ;
        b %= mod ;
        w %= mod ;
    }
    dp[v][0] = w ;
    dp[v][1] = b ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n-1){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(0,-1) ;
    cout << (dp[0][0] + dp[0][1]) % mod << endl ;
}