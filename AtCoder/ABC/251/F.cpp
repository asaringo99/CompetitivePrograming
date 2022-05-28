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
vector<int> G[202020] ;
bool use_dfs[202020] , use_bfs[202020] ;
vector<P> vec_dfs , vec_bfs ;

void dfs(int v){
    use_dfs[v] = true ;
    for(int u : G[v]){
        if(use_dfs[u]) continue;
        vec_dfs.push_back(P(u+1,v+1)) ;
        dfs(u) ;
    }
}

void bfs(){
    queue<int> que ;
    que.push(0) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        use_bfs[v] = true ;
        for(int u : G[v]){
            if(use_bfs[u]) continue;
            use_bfs[u] = true ;
            vec_bfs.push_back(P(v+1,u+1)) ;
            que.push(u) ;
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
    dfs(0) ;
    for(P p : vec_dfs) cout << p.first << " " << p.second << endl ;
    for(P p : vec_bfs) cout << p.first << " " << p.second << endl ;
}