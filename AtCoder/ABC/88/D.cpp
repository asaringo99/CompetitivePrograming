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

const int dx[4] = {0,0,-1,1} , dy[4] = {1,-1,0,0} ;

int H , W ;
char S[50][50] ;
int BW[50][50] ;

int bfs(int black){
    for(int i = 0 ; i < H ; i++) fill(BW[i],BW[i]+W,INT_MAX) ;
    BW[0][0] = 1 ;
    queue<P> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.' && BW[nx][ny] > BW[x][y] + 1){
                BW[nx][ny] = BW[x][y] + 1 ;
                que.push(P(nx,ny)) ;
            }
        }
    }
    if(BW[H-1][W-1] == INT_MAX) return -1 ;
    else return H * W - black - BW[H-1][W-1] ;
}

int main(){
    cin >> H >> W ;
    int black = 0 ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> S[i][j] ;
            if(S[i][j] == '#') black++ ;
        }
    }
    cout << bfs(black) << endl ;
}