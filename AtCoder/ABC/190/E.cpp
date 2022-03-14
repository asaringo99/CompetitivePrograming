#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)1e5
#define MAX_K (ll)17
#define INF (ll)1e16
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n , m , k ;

ll d[MAX_N] ;
vector<int> G[MAX_N] ;
vector<int> st ;
ll dist[MAX_K][MAX_K] ;

void dijkistra(){
    for(int i = 0 ; i < k ; i++) fill(dist[i],dist[i]+k,INF) ;
    for(int i = 0 ; i < k ; i++){
        fill(d,d+n,INF) ;
        int node = st[i] ;
        priority_queue<P,vector<P>,greater<P>> que ;
        d[node] = 0 ;
        que.push(P(0,node)) ;
        while(!que.empty()){
            P p = que.top() ; que.pop() ;
            int v = p.second ;
            if(d[v] < p.first) continue ;
            for(int j = 0 ; j < G[v].size() ; j++){
                int u = G[v][j] ;
                if(d[u] > d[v] + 1){
                    d[u] = d[v] + 1 ;
                    que.push(P(d[u],u)) ;
                }
            }
        }
        for(int j = 0 ; j < k ; j++){
            dist[i][j] = min(dist[i][j],d[st[j]]) ;
            dist[j][i] = min(dist[j][i],d[st[j]]) ;
        }
    }
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    cin >> k ;
    for(int i = 0 ; i < k ; i++){
        int s ;
        cin >> s ;
        s-- ;
        st.push_back(s) ;
    }
    dijkistra() ;
    ll dp[1 << k][k] ;
    for(int i = 0 ; i < (1 << k) ; i++) fill(dp[i],dp[i]+k,INF) ;
    fill(dp[(1 << k) - 1],dp[(1 << k) - 1] + k , 0) ;
    for(int i = (1 << k) - 2 ; i >= 0 ; i--){
        for(int j = 0 ; j < k ; j++){
            if(!(i >> j & 1)) continue ;
            for(int h = 0 ; h < k ; h++){
                if(i >> h & 1) continue ;
                dp[i][j] = min(dp[i][j],dp[i | 1 << h][h] + dist[j][h]) ;
            }
        }
    }
    ll ans = INF ;
    for(int i = 0 ; i < k ; i++){
        ans = min(ans , dp[1 << i][i]) ;
    }
    ans++ ;
    if(ans > INF) ans = -1 ;
    cout << ans << endl ;
}