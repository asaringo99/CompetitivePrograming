#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

ll d[MAX_N][MAX_N] ;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++) fill(d[i],d[i]+n,INT_MAX) ;
    for(int i = 0 ; i < n ; i++) d[i][i] = 0 ;
    for(int i = 0 ; i < m ; i++){
        int a , b , t ;
        cin >> a >> b >> t ;
        a-- ;
        b-- ;
        d[a][b] = t ;
        d[b][a] = t ;
    }
    warshall_floyd() ;
    ll res = INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        ll tmp = 0 ;
        for(int j = 0 ; j < n ; j++){
            tmp = max(tmp,d[i][j]) ;
        }
        res = min(res,tmp) ;
    }
    cout << res << endl ;
}