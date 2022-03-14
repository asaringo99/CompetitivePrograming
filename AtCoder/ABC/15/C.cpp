#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
int T[10][10] ;

int dfs(int v , int score){
    if(v == n) return score ;
    int res = INT_MAX ;
    rep(i,k){
        res = min(res,dfs(v+1,score ^ T[v][i])) ;
    }
    return res ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) rep(j,k) cin >> T[i][j] ;
    if(dfs(0,0) > 0) cout << "Nothing" << endl ;
    else cout << "Found" << endl ;
}