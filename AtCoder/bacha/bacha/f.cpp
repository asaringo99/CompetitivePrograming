#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int dx[4] = {1,0,0,-1} , dy[4] = {0,1,-1,0} ;

int H , W ;
int A[1010][1010] , B[1010][1010] ;
ll d[1010][1010][2] ;

void bfs(){
    rep(i,H) rep(j,W) rep(k,2) d[i][j][k] = 1e9 ;
    d[0][0][0] = 0 ;
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push({0,0,0,0}) ;
    while(!que.empty()){
        TP tp = que.top() ; que.pop() ;
        auto [dist,flag,x,y] = tp ;
        if(d[x][y][flag] < dist) continue ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue ;
            ll cost = 0 ;
            if(i == 0) cost = B[x][y] ;
            if(i == 1) cost = A[x][y] ;
            if(i == 2) cost = A[x][y-1] ;
            if(i == 3) cost = flag ? 1 : 2 ;
            if(i != 3){
                if(d[nx][ny][0] > d[x][y][flag] + cost){
                    d[nx][ny][0] = d[x][y][flag] + cost ;
                    que.push({d[nx][ny][0],0,nx,ny}) ;
                }
            }
            else {
                if(d[nx][ny][1] > d[x][y][flag] + cost){
                    d[nx][ny][1] = d[x][y][flag] + cost ;
                    que.push({d[nx][ny][1],1,nx,ny}) ;
                }
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) rep(j,W-1) cin >> A[i][j] ;
    rep(i,H-1) rep(j,W) cin >> B[i][j] ;
    bfs() ;
    cout << d[H-1][W-1][0] << endl ;
}