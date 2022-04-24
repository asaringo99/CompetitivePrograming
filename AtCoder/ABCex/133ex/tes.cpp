#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

struct edge
{
    int to ;
    ll cost ;
    int color ;
};


int n , q ;
map<int,int> C[MAX_N] ;
map<int,int> CL[MAX_N] ;
vector<edge> G[MAX_N] ;
int d[MAX_N] ;
int preview[MAX_N] ;
bool used[MAX_N] ;

void dfs(int v , int cost){
    d[v] = cost ;
    used[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        edge e = G[v][i] ;
        if(!used[e.to]){
            CL[e.to] = CL[v] ;
            CL[e.to][e.color] += e.cost ;
            C[e.to] = C[v] ;
            C[e.to][e.color]++ ;
            if(G[v].size() == 1) preview[e.to] = preview[v] ;
            else preview[e.to] = v ;
            dfs(e.to,cost+e.cost) ;
        }
    }
}

int main(){
    memset(used,0,sizeof(used)) ;
    cin >> n >> q ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        a-- ;
        b-- ;
        G[a].push_back(edge{b,d,c}) ;
        G[b].push_back(edge{a,d,c}) ;
    }
    preview[0] = 0 ;
    d[0] = 0 ;
    dfs(0,0) ;
    for(int i = 0 ; i < q ; i++){
        int x , y , v , u , node , dist ;
        cin >> x >> y >> v >> u ;
        v-- ;
        u-- ;
        if(preview[v] == preview[u]) dist = abs(d[u] - d[v]) ;
        else{
            int node_u = preview[u] , node_v = preview[v] ;
            bool good = true ;
            while(good){
                node_u = preview[node_u] ;
                bool ok = true ;
                while(ok){
                    if(node_v == 0) ok = false ;
                    if(node_u == node_v) {
                        node = node_u ;
                        ok = false ;
                        good = false ;
                    }
                    node_v = preview[node_v] ;
                }
            }
            dist = abs(d[u] + d[v] - d[node_u]) ;
        }
        dist -= (CL[u][x] + CL[v][x] - CL[node][x]) ;
        dist += (C[u][x] + C[v][x] - C[node][x]) * y ;
        cout << dist << endl ;
    }
}