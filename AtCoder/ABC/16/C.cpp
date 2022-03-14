#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int d[20][20] , ans[20] ;
int n , m;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) rep(j,n) d[i][j] = i == j ? 0 : 100000000 ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        d[a][b] = 1 ;
        d[b][a] = 1 ;
    }
    memset(ans,0,sizeof(ans)) ;
    warshall_floyd() ;
    rep(i,n){
        rep(j,n){
            if(d[i][j] == 2) ans[i]++ ;
        }
    }
    rep(i,n) cout << ans[i] << endl ;
}