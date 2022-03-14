#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e6
#define INF (ll)1e16

struct edge
{
  int to ;
  ll cost ;
};

int n ;

ll d[MAX_N] ;
vector<edge> V[MAX_N] ;

void djikstra(int s){
  fill(d,d+n,INF) ;
  d[s] = 0 ;
  priority_queue<P,vector<P>,greater<P>> que ;
  que.push(P(0,s)) ;
  while(!que.empty()){
    P p = que.top() ; que.pop() ;
    int v = p.second ;
    if(d[v] < p.first) continue ;
    for(int i = 0 ; i < V[v].size() ; i++){
      edge E = V[v][i] ;
      if(d[E.to] > d[v] + E.cost){
        d[E.to] = d[v] + E.cost ;
        que.push(P(d[E.to],E.to)) ;
      }
    }
  }
}

int main(){
  cin >> n ;
  for(int i = 0 ; i < n - 1 ; i++){
    int s , t ; ll w ;
    cin >> s >> t >> w ;
    edge E , F ;
    E.to = s - 1 ;
    E.cost = w ;
    F.to = t - 1 ;
    F.cost = w ;
    V[t-1].push_back(E) ;
    V[s-1].push_back(F) ;
  }
  djikstra(0) ;
  for(int i = 0 ; i < n ; i++){
    if(d[i] % 2 == 0) cout << 0 << endl ;
    else cout << 1 << endl ;
  }
}