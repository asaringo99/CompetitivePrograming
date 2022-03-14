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
priority_queue<P,vector<P>,greater<P>> Q ;
struct edge {int to , cost ;} ;
vector<edge> G[MAX_N] ;
int d[MAX_N] ;
int d2[MAX_N] ;

int solve(int s){
  fill(d,d+n,INFO) ;
  fill(d2,d2+n,INFO) ;
  d[s] = 0 ;
  Q.push(P(0,s)) ;
  while(!Q.empty()){
    P newP = Q.top() ;
    Q.pop() ;
    int dis = newP.first ;
    int pos = newP.second ;
    if(dis > d2[pos]) continue ;
    for(edge e : G[pos]){
      int dis2 = dis + e.cost ;
      if(dis2 < d[e.to]){
        Q.push(P(dis2,e.to)) ;
        swap(dis2,d[e.to]) ;
        d2[e.to] = dis2 ;
      }
      if(dis2 > d[e.to] && dis2 < d2[e.to]){
        Q.push(P(dis2,e.to)) ;
        d2[e.to] = dis2 ;
      }
    }
  }
}