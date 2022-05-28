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

int n , m ;
vector<int> G[101010] ;
int d[101010] ;
int s[2] ;
bool ok = false ;

void bfs(){
    rep(i,n) d[i] = 1e9 ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        auto [dist,v] = que.top() ; que.pop() ;
        if(dist > d[v]) continue;
        s[dist%2]++ ;
        for(int u : G[v]){
            if(d[u] == d[v]) ok = true ;
            if(d[u] > d[v] + 1){
                d[u] = d[v] + 1 ;
                que.push(P(d[u],u)) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    bfs() ;
    ll res = 0 ;

    rep(i,n){
        int dist = d[i] % 2 ;
        res += s[(dist^1)] - (int)G[i].size() ;
        if(ok) res += s[dist] - 1 ;
    }
    cout << res / 2 << endl ;
}