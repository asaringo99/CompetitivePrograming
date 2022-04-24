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

int n, q ;

int dist[202020] ;
vector<int> d[202020] ;
vector<int> G[202020] ;
vector<P> query[202020] ;
int res[202020] ;

int tim = 0 ;
void dfs(int v , int prev){
    vector<int> vv ;
    for(int i = 0 ; i < query[v].size() ; i++) vv.push_back(d[query[v][i].first].size()) ;
    d[dist[v]].push_back(v) ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dist[u] = dist[v] + 1 ;
        dfs(u,v) ;
    }
    for(int i = 0 ; i < query[v].size() ; i++) res[query[v][i].second] = d[query[v][i].first].size() - vv[i] ;
}

int main(){
    cin >> n ;
    rrep(i,1,n){
        int p ; 
        cin >> p ;
        p-- ;
        G[i].push_back(p) ;
        G[p].push_back(i) ;
    }
    cin >> q ;
    rep(i,q){
        int u , d ;
        cin >> u >> d ;
        u-- ;
        query[u].push_back(P(d,i)) ;
    }
    dfs(0,-1) ;
    rep(i,q) cout << res[i] << endl ;
}