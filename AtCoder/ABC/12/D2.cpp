#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int n , m ;
ll d[305][305] ;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    for(int i = 0 ; i < 305 ; i++) fill(d[i],d[i]+305,INT_MAX) ;
    for(int i = 0 ; i < 305 ; i++) d[i][i] = 0 ;
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        ll a , b , t ;
        cin >> a >> b >> t ;
        a-- ;
        b-- ;
        d[a][b] = t ;
        d[b][a] = t ;
    }
    warshall_floyd() ;
    ll cost = INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        ll val = 0 ;
        for(int j = 0 ; j < n ; j++){
            val = max(val,d[i][j]) ;
        }
        cost = min(cost,val) ;
    }
    cout << cost << endl ;
}