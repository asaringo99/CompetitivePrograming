#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;
int C[MAX_N] ;
bool ok[MAX_N] ;
bool d[MAX_N] ;
map<int,int> rem ;

vector<int> G[MAX_N] ;

void dfs(int v){
    if(rem[C[v]] == 0) ok[v] = true ;
    rem[C[v]]++ ;
    d[v] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(d[u]) continue ;
        dfs(u) ;
    }
    rem[C[v]]-- ;
}

int main(){
    cin >> n ;
    memset(ok,0,sizeof(ok)) ;
    memset(d,0,sizeof(d)) ;
    for(int i = 0 ; i < n ; i++) cin >> C[i] ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    map<int,bool> S ;
    dfs(0) ;
    for(int i = 0 ; i < n ; i++) if(ok[i]) cout << i + 1 << endl ;
}