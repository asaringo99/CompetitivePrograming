#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> P ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
#define MAX_N 1000
#define inf 100000000

int H , W ;
int CH , CW ;
int DH , DW ;
char S[MAX_N][MAX_N] ;
int MGC[MAX_N][MAX_N] ;

int d[5] = {0,-1,1,2,-2} ;

void bfs(int s , int t){
  queue<P> que ;
  que.push(P(s,t)) ;
  while(!que.empty()){
    P p = que.front() ; que.pop() ;
    int x = p.first , y = p.second ;
    for(int i = -2 ; i <= 2 ; i++){
      for(int j = -2 ; j <= 2 ; j++){
        if(i == 0 && j == 0) continue ;
        int nx = x + i , ny = y + j ;
        if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.'){
          if((abs(i) + abs(j) >= 2) && MGC[nx][ny] > MGC[x][y] + 1){
            MGC[nx][ny] = MGC[x][y] + 1 ;
            que.push(P(nx,ny)) ;
          }
          if((abs(i) + abs(j) <= 1) && MGC[nx][ny] > MGC[x][y]){
            MGC[nx][ny] = MGC[x][y] ;
            que.push(P(nx,ny)) ;
          }
        }
      }
    }
  }
}

int main(){
  cin >> H >> W ;
  cin >> CH >> CW ;
  cin >> DH >> DW ;
  CH-- ;
  CW-- ;
  DH-- ;
  DW-- ;
  for(int i = 0 ; i < H ; i++)
    for(int j = 0 ; j < W ; j++) cin >> S[i][j] ;
  for(int i = 0 ; i < H ; i++) fill(MGC[i],MGC[i]+W,inf) ;
  MGC[CH][CW] = 0 ;
  bfs(CH,CW) ;
  if(MGC[DH][DW] == inf) cout << -1 << endl ;
  else cout << MGC[DH][DW] << endl ;
}