#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<int>> ;
using Pair = pair<int,int> ;
using ll = long long ;
using que = queue<Pair> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_V 100
#define INF 10005

struct edge{int to ; ll cost ;};
int N ;
vector<edge> ED[INF] ;
bool used[INF] ;
bool color[INF] ;

void solve(int v){
  queue<int> Q ;
  Q.push(v) ;
  color[v] = 1 ;
  while(!Q.empty()){
    int v = Q.front() ;
    Q.pop() ;
    if(used[v]) continue ;
    for(edge e : ED[v]){
      int u = e.to ;
      if(e.cost % 2 == 0) color[u] = color[v] ;
      else color[u] = abs(color[v] - 1) ;
      Q.push(u) ;
    }
    used[v] = true ;
  }
}

int main(){
  cin >> N ;
  int U , V ;
  ll D ;
  fill(used,used+INF,true) ;
  fill(color,color+INF,0) ;
  for(int i = 0 ; i < N - 1 ; i++){
    cin >> U >> V >> D ;
    edge newE ;
    newE.to = V - 1 ; newE.cost = D ;
    ED[U-1].push_back(newE) ;
    used[U-1] = false ;
    newE.to = U - 1 ; newE.cost = D ;
    ED[V-1].push_back(newE) ;
    used[V-1] = false ;
  }
  solve(0) ;
  for(int i = 0 ; i < N ; i++) cout << color[i] << endl ;
}