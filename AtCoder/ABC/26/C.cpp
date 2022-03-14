#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
vector<int> G[50] ;

ll p[50] ;
ll rec(int v){
    ll res = 1 , minval = 1e18 , maxval = -1e18 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        minval = min(minval,rec(u)) ;
        maxval = max(maxval,rec(u)) ;
    }
    if(minval == 1e18) minval = 0 ;
    if(maxval == -1e18) maxval = 0 ;
    return res + minval + maxval ;
}

int main(){
    cin >> n ;
    rep(i,n-1){
        int b ;
        cin >> b ;
        G[--b].push_back(i+1) ;
    }
    cout << rec(0) << endl ;
}