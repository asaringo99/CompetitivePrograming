#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , a , b , m ;
vector<int> G[300] ;

bool used[300] ;
int dp[300] ;
int d[300] ;

void bfs(){
    rep(i,n) d[i] = 10000 ;
    d[a] = 0 ;
    dp[a] = 1 ;
    queue<int> que ;
    que.push(a) ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(d[u] == d[v] + 1){
                (dp[u] += dp[v]) %= mod ;
            }
            else if(d[u] > d[v] + 1){
                dp[u] = dp[v] ;
                d[u] = d[v] + 1 ;
                que.push(u) ;
            }
        }
    }
}

int main(){
    cin >> n >> a >> b >> m ;
    a-- ;
    b-- ;
    rep(i,m){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        G[x].push_back(y) ;
        G[y].push_back(x) ;
    }
    bfs() ;
    cout << dp[b] << endl ;
}