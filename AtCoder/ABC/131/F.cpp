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
int X[101010] ;
bool used[202020] ;
vector<int> G[202020] ;
map<P,bool> mp ;
ll x , y , d ;

void dfs(int v , int prev){
    used[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(prev == u) continue ;
        if(!mp[P(min(v,u),max(v,u))]) d++ ;
        mp[P(min(v,u),max(v,u))] = true ;
        if(used[u]) continue ;
        dfs(u,v) ;
    }
    if(v < 1e5) x++ ;
    else y++ ;
}

int main(){
    cin >> n ;
    rep(i,n){
        int u , v ;
        cin >> u >> v ;
        u-- ;
        v-- ;
        X[i] = u ;
        G[u].push_back((int)1e5+v) ;
        G[(int)1e5+v].push_back(u) ;
    }
    ll res = 0 ;
    rep(i,n){
        int v = X[i] ;
        if(used[v]) continue ;
        x = 0 ;
        y = 0 ;
        d = 0 ;
        dfs(v,-1) ;
        res += x * y - d ;
    }
    cout << res << endl ;
}