#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define MAX_N (ll)2000
#define INF INT_MAX
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int dx[4] = {0,0,-1,1} , dy[4] = {-1,1,0,0} ;

int H , W ;
char S[MAX_N][MAX_N] ;
int d[MAX_N][MAX_N] ;
map<char,bool> alf ;
map<char,vector<P>> cor ;

void bfs(int x , int y){
    priority_queue<TP,vector<TP>,greater<TP>> que ;
    que.push(TP(0,x,y)) ;
    for(int i = 0 ; i < H ; i++) fill(d[i],d[i]+W,INF) ;
    d[x][y] = 0 ;
    while(!que.empty()){
        TP tp = que.top() ; que.pop() ;
        int x , y , dist ;
        tie(dist,x,y) = tp ;
        if(dist > d[x][y]) continue ;
        if(cor[S[x][y]].size() != 0 && !alf[S[x][y]]){
            alf[S[x][y]] = true ;
            vector<P> tmp = cor[S[x][y]] ;
            for(P u : tmp){
                if(u != P(x,y) && d[u.first][u.second] > d[x][y] + 1){
                    d[u.first][u.second] = d[x][y] + 1 ;
                    que.push(TP(d[u.first][u.second],u.first,u.second)) ;
                }
            }
        }
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] != '#' && d[nx][ny] > d[x][y] + 1){
                d[nx][ny] = d[x][y] + 1 ;
                que.push(TP(d[nx][ny],nx,ny)) ;
            }
        }
    }
}

int main(){
    cin >> H >> W ;
    map<int,int> rem ;
    int sx , sy , gx , gy ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> S[i][j] ;
            if(S[i][j] != '#' && S[i][j] != '.' && S[i][j] != 'S' && S[i][j] != 'G'){
                cor[S[i][j]].push_back(P(i,j)) ;
            }
            if(S[i][j] == 'S'){
                sx = i ;
                sy = j ;
            }
            if(S[i][j] == 'G'){
                gx = i ;
                gy = j ;
            }
        }
    }
    bfs(sx,sy) ;
    int ans = d[gx][gy] ;
    if(ans == INF) ans = -1 ;
    cout << ans << endl ;
    //for(P p : cor['a']) cout << p.first << " " << p.second << endl ;
}