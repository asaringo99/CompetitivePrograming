#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
vector<int> G[606] ;
ld dp[606] ;

inline ld rec(int v , int b){
    if(v == n - 1) return dp[v] = 0 ;
    if(dp[v] >= 0) return dp[v] ;
    ld res = 0 , val = 0 ;
    int m = G[v].size() ;
    for(int i = 0 ; i < m ; i++){
        int u = G[v][i] ;
        ld x = rec(u,b) ;
        res += x ;
        chmax(val,x) ;
    }
    if(m != 1 && v == b){
        m-- ;
        res -= val ;
    }

    return dp[v] = res / m + 1 ;
}

int main(){
    cin >> n >> m ;
    rep(i,m){
        int s , t ;
        cin >> s >> t ;
        s-- ; t-- ;
        G[s].push_back(t) ;
    }
    ld res = 1e18 ;
    rep(i,n){
        rep(j,n) dp[j] = -1 ;
        chmin(res,rec(0,i)) ;
    }
    cout << fixed << setprecision(20) << res << endl ;
}