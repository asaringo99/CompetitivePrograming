#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
int n , k ;

vector<int> G[101010] ;

ll dfs(int v , int prev , ll p){
    ll res = 1 , cnt = 0 ; ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        ll q = prev == -1 ? 1 : 2 ;
        (res *= dfs(u,v,k-q-cnt)) %= mod ;
        cnt++ ;
    }
    return (res *= p) %= mod ;
}

int main(){
    cin >> n >> k ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    cout << dfs(0,-1,k) << endl ;
}