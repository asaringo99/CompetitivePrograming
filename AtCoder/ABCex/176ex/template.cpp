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

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;

int H , W ;
int sx , sy , gx , gy ;
char S[1010][1010] ;
int d[1010][1010] ;

void bfs_01(){
    rep(i,H) rep(j,W) d[i][j] = 1e8 ;
    d[sx][sy] = 0 ;
    queue<P> que_0 , que_1 ;
    que_0.push(P(sx,sy)) ;
    while(!que_0.empty() || !que_1.empty()){
        while(!que_0.empty()){
            auto [x,y] = que_0.front() ; que_0.pop() ;
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i] , ny = y + dy[i] ;
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '#') continue ;
                if(d[nx][ny] > d[x][y]){
                    d[nx][ny] = d[x][y] ;
                    que_0.push(P(nx,ny)) ;
                }
            }
            que_1.push(P(x,y)) ;
        }
        while(!que_1.empty()){
            auto [x,y] = que_1.front() ; que_1.pop() ;
            rrep(i,-2,3) rrep(j,-2,3){
                int nx = x + i , ny = y + j ;
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '#') continue ;
                if(d[nx][ny] > d[x][y] + 1) {
                    d[nx][ny] = d[x][y] + 1 ;
                    que_0.push(P(nx,ny)) ;
                }
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> H >> W >> sx >> sy >> gx >> gy ;
    sx-- ; sy-- ; gx-- ; gy-- ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    bfs_01() ;
    int res = d[gx][gy] ;
    if(res == 1e8) res = -1 ;
    cout << res << endl ;
}