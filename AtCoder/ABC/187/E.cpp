#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define MAX_N (ll)2e5

int n , q ;

int depth[MAX_N] ;
vector<int> V[MAX_N] ;
ll G[MAX_N] ;

void depth_tree(int s){
  fill(depth,depth+n,MAX_N + 7) ;
  depth[s] = 0 ;
  queue<int> que ;
  que.push(s) ;
  while(!que.empty()){
    int v = que.front() ; que.pop() ;
    for(int i = 0 ; i < V[v].size() ; i++){
      int u = V[v][i] ;
      if(depth[u] != depth[v] - 1){
        depth[u] = depth[v] + 1 ;
        que.push(u) ;
      }
    }
  }
}

void imos_rootedtree(int s){
  queue<int> que ;
  que.push(s) ;
  while(!que.empty()){
    int v = que.front() ; que.pop() ;
    for(int i = 0 ; i < V[v].size() ; i++){
      int u = V[v][i] ;
      if(depth[u] < depth[v]) continue ;
      G[u] += G[v] ;
      que.push(u) ;
    }
  }
}

int main(){
  cin >> n ;
  fill(G,G+n,0) ;
  pair<int,int> node[n-1] ;
  for(int i = 0 ; i < n - 1 ; i++){
    int a , b ;
    cin >> a >> b ;
    a-- ; b-- ;
    V[a].push_back(b) ;
    V[b].push_back(a) ;
    node[i].first = a ;
    node[i].second = b ;
  }

  depth_tree(0) ;

  cin >> q ;
  for(int i = 0 ; i < q ; i++){
    int t , e ;
    ll x ; 
    cin >> t >> e >> x ;
    e-- ;
    int u , v ;
    if(t == 1){
      u = node[e].first ;
      v = node[e].second ;
    }
    else{
      u = node[e].second ;
      v = node[e].first ;
    }
    if(depth[u] > depth[v]) G[u] += x ;
    else{
      G[0] += x ; 
      G[v] -= x ;
    }
  }

  imos_rootedtree(0) ;
  for(int i = 0 ; i < n ; i++) cout << G[i] << endl ;
}