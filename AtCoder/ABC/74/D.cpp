#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[500][500] ;
ll d[500][500] ;

void warshall(){rep(k,n) rep(i,n) rep(j,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]) ; }
ll f(){
    ll res = 0 ;
    rep(i,n) rrep(j,i+1,n) {
        bool ok = true ;
        rep(k,n) if(i != k && j != k) if(d[i][j] >= d[i][k] + d[k][j]) ok = false ;
        if(ok) res += d[i][j] ;
    }
    return res ;
}

int main(){
    cin >> n ;
    rep(i,n) rep(j,n) cin >> A[i][j] ;
    rep(i,n) rep(j,n) d[i][j] = A[i][j] ;
    warshall() ;
    bool ok = true ;
    rep(i,n) rep(j,n) if(d[i][j] != A[i][j]) ok = false ;
    if(!ok){
        cout << -1 << endl ;
        return 0 ;
    }
    cout << f() << endl ;
}