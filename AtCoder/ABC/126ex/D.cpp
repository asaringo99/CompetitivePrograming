#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

struct edge{int to ; ll cost ;};

vector<edge> G[MAX_N] ;
ll d[MAX_N] ;

void djikstra(){
    fill(d,d+n,1000000000000000) ;
    d[0] = 0 ;
    priority_queue<P,vector<P>,greater<P>> que ;
    que.push(P(0,0)) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        int v = p.second ;
        if(d[v] < p.first) continue ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],e.to)) ;
            }
        }
    }
    return ;
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b , w ;
        cin >> a >> b >> w ;
        a-- ;
        b-- ;
        G[a].push_back(edge{b,w}) ;
        G[b].push_back(edge{a,w}) ;
    }
    djikstra() ;
    for(int i = 0 ; i < n ; i++){
        if(d[i] % 2 == 0) cout << 0 << endl ;
        else cout << 1 << endl ;
    }
    return 0 ;
}