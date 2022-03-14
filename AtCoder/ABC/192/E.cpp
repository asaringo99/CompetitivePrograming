#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_M (ll)100
#define MAX_N 100000

int n , m , X , Y ;

struct edge
{
  ll cost ;
  ll limit ;
  int to ;
};


vector<edge> G[100000] ;
ll d[100000] ;

ll djikstra(int s , int t){
  fill(d,d+n,LLONG_MAX) ;
  d[s] = 0 ;
  priority_queue<P,vector<P>,greater<P>> que ;
  que.push(P(0,s)) ;
  while(!que.empty()){
    P p = que.top() ; que.pop() ;
    int v = p.second ;
    if(p.first > d[v]) continue ;
    for(int i = 0 ; i < G[v].size() ; i++){
      edge e = G[v][i] ;
      if(d[v] % e.limit == 0){
        if(d[e.to] > d[v] + e.cost){
          d[e.to] = d[v] + e.cost ;
          que.push(P(d[e.to],e.to)) ;
        }
      }
      else{
        ll mod = d[v] / e.limit + 1 ;
        if(d[e.to] > mod * e.limit + e.cost){
          d[e.to] = mod * e.limit + e.cost ;
          que.push(P(d[e.to],e.to)) ;
        }
      }
    }
  }
  return d[t] ;
}

int main(){
  cin >> n >> m >> X >> Y ;
  for(int i = 0 ; i < m ; i++){
    int A , B ;
    ll tim , k ;
    cin >> A >> B >> tim >> k ;
    edge E , F ;
    E.to = B - 1 ;
    E.cost = tim ;
    E.limit = k ;
    F.to = A - 1 ;
    F.cost = tim ;
    F.limit = k ;
    G[A-1].push_back(E) ;
    G[B-1].push_back(F) ;
  }
  ll ans = djikstra(X-1,Y-1) ;
  if(ans == LLONG_MAX) cout << -1 << endl ;
  else cout << ans << endl ;
}