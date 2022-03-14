#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W , T ;
char S[20][20] ;
ll d[20][20] ;

int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;
int sx , sy , gx , gy ;

ll bfs(ll m){
    rep(i,H) rep(j,W) d[i][j] = (ll)1e15 ;
    queue<P> que ;
    que.push(P(sx,sy)) ;
    d[sx][sy] = 0 ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 <= nx && nx < H && 0 <= ny && ny < W){
                if(S[nx][ny] == '#' && d[nx][ny] > d[x][y] + m){
                    d[nx][ny] = d[x][y] + m ;
                    que.push(P(nx,ny)) ;
                }
                if((S[nx][ny] == '.' || S[nx][ny] == 'G') && d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1 ;
                    que.push(P(nx,ny)) ;
                }
            }
        }
    }
    return d[gx][gy] ;
}

int main(){
    cin >> H >> W >> T ;
    rep(i,H) rep(j,W) {
        cin >> S[i][j] ;
        if(S[i][j] == 'S'){
            sx = i ;
            sy = j ;
        }
        if(S[i][j] == 'G'){
            gx = i ;
            gy = j ;
        }
    }
    ll lef = 1 , rig = (ll)1e18 ;
    while(rig - lef > 0){
        ll m = (lef + rig) / 2 ;
        // cout << lef << " " << rig << " " ;
        if(bfs(m) <= T) lef = m + 1 ;
        else rig = m ;
        // cout << bfs(m) << endl; 
    }
    cout << rig - 1 << endl ;
}