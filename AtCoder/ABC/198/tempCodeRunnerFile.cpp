#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef map<int,bool> mp ;
typedef pair<int,mp> PP ;
typedef pair<int,PP> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

struct edge
{
    int to ;
    int cost ;
};

int d[MAX_N] ;
vector<edge> G[MAX_N] ;
int C[MAX_N] ;
bool ok[MAX_N] ;

void dijkstra(){
    memset(ok,1,sizeof(ok)) ;
    fill(d,d+n,INT_MAX) ;
    d[0] = 0 ;
    mp S ;
    S[C[0]] = true ;
    priority_queue<P,vector<P>,greater<P>> que ; 
    que.push(P(0,PP(0,S))) ;
    while(!que.empty()){
        P p = que.top() ; que.pop() ;
        PP pp = p.second ;
        int v = pp.first ;
        if(d[v] < p.first) continue ;
        mp SS = pp.second ;
        for(int i = 0 ; i < G[v].size() ; i++){
            edge e = G[v][i] ;
            if(d[e.to] > d[v] + e.cost){
                mp S = SS ;
                if(S[C[e.to]]) ok[e.to] = false ;
                S[C[e.to]] = true ;
                PP ppp = PP(e.to,S) ;
                d[e.to] = d[v] + e.cost ;
                que.push(P(d[e.to],ppp)) ;
            }
        }
    }
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> C[i] ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(edge{b,1}) ;
        G[b].push_back(edge{a,1}) ;
    }
    dijkstra() ;
    for(int i = 0 ; i < n ; i++){
        if(ok[i]) cout << i + 1 << endl ; 
    }
}