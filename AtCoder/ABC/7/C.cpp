#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int R , C ;
int sx , sy , gx , gy ;
char S[50][50] ;
int d[50][50] ;

const int dx[4] = {0,0,1,-1} , dy[4] = {1,-1,0,0} ;

int bfs(int sx , int sy){
    for(int i = 0 ; i < 50 ; i++) fill(d[i],d[i]+50,INT_MAX) ;
    queue<P> que ;
    que.push(P(sx,sy)) ;
    d[sx][sy] = 0 ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 <= nx && nx < R && 0 <= ny && ny < C && d[nx][ny] > d[x][y] + 1 && S[nx][ny] == '.'){
                d[nx][ny] = d[x][y] + 1 ;
                que.push(P(nx,ny)) ;
            }
        }
    }
    return d[gx][gy] ;
}

int main(){
    cin >> R >> C ;
    cin >> sx >> sy >> gx >> gy ;
    sx-- ;
    sy-- ;
    gx-- ;
    gy-- ;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> S[i][j] ;
        }
    }
    cout << bfs(sx,sy) << endl ;
}