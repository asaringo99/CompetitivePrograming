#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[1010] ;
map<P,bool> mp ;

vector<int> G[1010] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ; 
    return gcd(b,a%b) ;
}

void dfs(int s , int v , int prev , int val , int& res){
    val = gcd(val,A[v]) ;
    if(s != v && val == 1 && !mp[P(min(s,v),max(s,v))]) res++ ;    
    mp[P(min(s,v),max(s,v))] = true ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(s,u,v,val,res) ;
    }
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n-1){
        int v , u ;
        cin >> v >> u ;
        v-- ; u-- ;
        G[v].push_back(u) ;
        G[u].push_back(v) ;
    }
    int res = 0 ;
    rep(i,n) dfs(i,i,-1,0,res) ;
    cout << res << endl ;
}