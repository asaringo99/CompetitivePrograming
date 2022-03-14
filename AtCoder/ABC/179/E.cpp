#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)

ll n , m , x ;

ll S[55][101010] , G[55][101010] ;

ll doubling(ll x , ll n){
    rep(i,m) S[0][i] = i ;
    rep(i,m) G[0][i] = i * i % m ;
    int v = x ;
    ll res = 0 ;
    rep(i,50) {
        if(n >> i & 1){
        res += S[i][v] ;
        v = G[i][v] ;
        }
        rep(j,m){
            G[i+1][j] = G[i][G[i][j]] ;
            S[i+1][j] = S[i][G[i][j]] + S[i][j] ;
        }
    }
    return res ;
}

int main(){
    cin >> n >> x >> m ;
    cout << doubling(x,n) << endl ;
}