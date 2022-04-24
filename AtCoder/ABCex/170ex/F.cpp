#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<ll,ll,int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1} ;

int H , W , k , s0 , t0 , s1 , t1 ;
vector<vector<char>> C ;
vector<vector<ll>> d[4] ;

priority_queue<TP,vector<TP>,greater<TP>> que ;

void dijkstra(int s , int t){
    rep(m,4) rep(i,H) rep(j,W) d[m][i][j] = 1e16 ;
    d[0][s][t] = 0 ;
    d[1][s][t] = 0 ;
    d[2][s][t] = 0 ;
    d[3][s][t] = 0 ;
    que.push({0,0,0,s,t}) ;
    que.push({0,0,1,s,t}) ;
    que.push({0,0,2,s,t}) ;
    que.push({0,0,3,s,t}) ;
    while(!que.empty()){
        TP tp = que.top() ; que.pop() ;
        ll dist , re , dir , x , y ;
        tie(dist,re,dir,x,y) = tp ;
        if(d[dir][x][y] < dist) continue ;
        if(re == 0) re = k ;
        int nx = x + dx[dir] , ny = y + dy[dir] ;
        if(0 > nx || nx >= H || 0 > ny || ny >= W || C[nx][ny] == '@') continue ;
        for(int i = 0 ; i < 4 ; i++){
            if(re == k){
                if(dir == i) if(d[i][nx][ny] > d[dir][x][y] + 1) {
                    d[i][nx][ny] = d[dir][x][y] + 1 ;
                    que.push({d[i][nx][ny],re-1,i,nx,ny}) ;
                }
                if(dir != i) if(d[i][nx][ny] > d[dir][x][y] + k) {
                    d[i][nx][ny] = d[dir][x][y] + k ;
                    que.push({d[i][nx][ny],k,i,nx,ny}) ;
                }
                continue ;
            }
            if(i == dir){
                if(d[i][nx][ny] > d[dir][x][y] + 1){
                    d[i][nx][ny] = d[dir][x][y] + 1 ;
                    que.push({d[i][nx][ny],re-1,i,nx,ny}) ;
                }
                continue ;
            }
            if(i != dir){
                if(d[i][nx][ny] > d[dir][x][y] / k * k + k){
                    d[i][nx][ny] = (d[dir][x][y]) / k * k + k ;
                    que.push({d[i][nx][ny],k,i,nx,ny}) ;
                }
                continue ;
            }
        }
    }
}

int main(){
    cin >> H >> W >> k >> s0 >> t0 >> s1 >> t1 ;
    s0-- ;
    t0-- ;
    s1-- ;
    t1-- ;
    C.resize(H,vector<char>(W)) ;
    rep(i,4) d[i].resize(H,vector<ll>(W)) ;
    rep(i,H) rep(j,W) cin >> C[i][j] ;
    dijkstra(s0,t0) ;
    ll res = 1e16 ;
    rep(i,4) res = min(res,d[i][s1][t1]) ;
    if(res == 1e16) cout << -1 << endl ;
    else{
        res = res % k == 0 ? res / k : res / k + 1 ;
        cout << res << endl ;
    }
}