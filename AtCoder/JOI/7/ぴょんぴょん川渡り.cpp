#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll d[202][20][101] ;
vector<P> vec[202] ;

void djikstra(){
    rep(i,n+2) rep(j,vec[i].size()) rep(k,m+1) d[i][j][k] = 1e16 ;
    d[0][0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0,0}) ;
    while(!que.empty()){
        ll dist , x , y , c ;
        tie(dist,x,y,c) = que.top() ; que.pop() ;
        // cout << dist << " " << x << " " << vec[x][y].first << " " << c << endl ;
        if(dist > d[x][y][c]) continue ;
        if(x == n + 1) continue ;
        ll nx = x + 1 , now = vec[x][y].second ; ;
        for(int i = 0 ; i < vec[nx].size() ; i++){
            ll ny = vec[nx][i].first , pre = vec[nx][i].second , py = vec[x][y].first ;
            // if(nx == 3) cout << "djljkl : " << ny << " " << py << " " << pre << " " << now << endl ;
            if(x == 0 || nx == n + 1) py = ny ;
            if(d[nx][i][c] > d[x][y][c] + (pre + now) * abs(ny - py)){
                d[nx][i][c] = d[x][y][c] + (pre + now) * abs(ny - py) ;
                que.push({d[nx][i][c],nx,i,c}) ;
            }
        }
        if(x == n || c == m) continue ;
        nx++ ;
        for(int i = 0 ; i < vec[nx].size() ; i++){
            ll ny = vec[nx][i].first , pre = vec[nx][i].second , py = vec[x][y].first ;
            if(x == 0 || nx == n + 1) py = ny ;
            if(d[nx][i][c+1] > d[x][y][c] + (pre + now) * abs(ny - py)){
                d[nx][i][c+1] = d[x][y][c] + (pre + now) * abs(ny - py) ;
                que.push({d[nx][i][c+1],nx,i,c+1}) ;
            }
        }
    }
}

int main(){
    cin >> n >> m ;
    vec[0].push_back(P(0,0)) ;
    rep(i,n){
        int k ;
        cin >> k ;
        rep(j,k){
            int a , x ;
            cin >> a >> x ;
            a-- ;
            vec[i+1].push_back(P(a,x)) ;
        }
    }
    vec[n+1].push_back(P(0,0)) ;
    djikstra() ;
    ll res = 1e16 ;
    rep(i,m+1) chmin(res,d[n+1][0][i]) ;
    cout << res << endl ;
}