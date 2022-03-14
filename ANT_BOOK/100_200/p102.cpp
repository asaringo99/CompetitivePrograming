#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 5000
#define INFO 1000000

int n , r ;
int d[MAX_N] ;
int d2[MAX_N] ;
int cost[MAX_N][MAX_N] ;
bool used[MAX_N] ;
bool used2[MAX_N] ;

int dijkstra(int s){
  fill(d,d+n,INFO) ;
  fill(d2,d2+n,INFO) ;
  fill(used,used,false) ;
  //fill(used2,used2,false) ;
  d[s] = 0 ;
  priority_queue<P,vector<P>,greater<P>> Q ;
  Q.push(P(0,0)) ;

  while(!Q.empty()){
    P p = Q.top() ;
    Q.pop() ;
    int dis = p.first , v = p.second ;
    if(dis > d2[v]) continue ;
    for(int u = 0 ; u < n ; u++){
      int dis2 = dis + cost[v][u] ;
      if(dis2 < d[u]){
        swap(dis2,d[u]) ;
        Q.push(P(d[u],u)) ;
      }
      if(dis2 < d2[u] && dis2 > d[u]){
        d2[u] = dis2 ;
        Q.push(P(d2[u],u)) ;
      }
    }
  }
}