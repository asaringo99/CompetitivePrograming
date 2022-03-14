#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
char S[30][30] ;

int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;
int d[30][30] ;

void bfs(int s , int t){
    rep(i,H) rep(j,W) d[i][j] = 10000 ;
    d[s][t] = 0 ;
    queue<P> que ;
    que.push(P(s,t)) ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.'){
                if(d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1 ;
                    que.push(P(nx,ny)) ;
                }
            }
        }
    }
}

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> S[i][j] ;
    int ans = 0 ;
    rep(i,H) rep(j,W){
        if(S[i][j] == '#') continue ;
        bfs(i,j) ;
        rep(k,H) rep(l,W) if(S[k][l] != '#') ans = max(ans,d[k][l]) ;
    }
    cout << ans << endl ;
}