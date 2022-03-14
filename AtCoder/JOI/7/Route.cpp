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

struct edge{
    int to ;
    int cost ;
};

int n , m ;
ll d[101][101] ;
P X[101] ;
vector<edge> G[101] ;

void djikstra(){
    rep(i,n) rep(j,n) d[i][j] = 1e16 ;
    d[0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0}) ;
    while(!que.empty()){
        int v , pre , dist ;
        tie(dist,v,pre) = que.top() ; que.pop() ;
        if(d[v][pre] < dist) continue;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            int nx = X[e.to].first , ny = X[e.to].second ;
            int px = X[pre].first , py = X[pre].second ;
            int x = X[v].first , y = X[v].second ;
            int dot = (px - x) * (x - nx) + (py - y) * (y - ny) ;
            if(d[e.to][v] > d[v][pre] + e.cost && dot >= 0){
                d[e.to][v] = d[v][pre] + e.cost ;
                que.push({d[e.to][v],e.to,v}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> X[i].first >> X[i].second ;
    rep(i,m){
        int x , y , z ;
        cin >> x >> y >> z ;
        x-- ; y-- ;
        G[x].push_back(edge{y,z}) ;
        G[y].push_back(edge{x,z}) ;
    }
    djikstra() ;
    ll res = 1e16 ;
    rep(i,n) chmin(res,d[1][i]) ;
    if(res == 1e16) res = -1 ;
    cout << res << endl ;
}