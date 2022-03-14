#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define INF (ll)1e12
#define MAX_N (ll)2e5

int N , Q ;

int main(){
  map<int,int> infantskill ;
  map<int,int> whereinfant ;
  vector<set<P,greater<P>>> schoolskill(MAX_N) ;
  set<P> EQL ;
  cin >> N >> Q ;
  for(int i = 0 ; i < N ; i++){
    int A , B ;
    cin >> A >> B ;
    B-- ;
    infantskill[i] = A ;
    whereinfant[i] = B ;
    schoolskill[B].insert(P(A,i)) ;
  }
  for(int i = 0 ; i < MAX_N ; i++){
    if(schoolskill[i].empty()) continue ;
    EQL.insert(*schoolskill[i].begin()) ;
    //P p = *schoolskill[i].begin() ;
    //cout << p.first << endl ;
  }

  vector<int> res ;
  for(int i = 0 ; i < Q ; i++){
    int c , d ;
    cin >> c >> d ;
    c-- ; d-- ;
    EQL.erase(*schoolskill[d].begin()) ;
    int u = whereinfant[c] ;
    int v = infantskill[c] ;
    EQL.erase(P(v,c)) ;
    P pp = *schoolskill[u].begin() ;
    schoolskill[u].erase(P(v,c)) ;
    if(!schoolskill[u].empty()) EQL.insert(*schoolskill[u].begin()) ;
    schoolskill[d].insert(P(v,c)) ;
    whereinfant[c] = d ;
    
    //cout << u << " -> " << d << " " << c << " skill is " << v << endl ;
    //auto it = EQL.find(P(v,c)) ;
    //if(it != EQL.end()) 
    
    EQL.insert(*schoolskill[d].begin()) ;
    
    //P pppp = *schoolskill[d].begin() ;
    //cout << d << " -> " << pppp.first << endl ;
    P p = *EQL.begin() ;
    res.push_back(p.first) ;
  }
  for(int i = 0 ; i < Q ; i++) cout << res[i] << endl ;
}