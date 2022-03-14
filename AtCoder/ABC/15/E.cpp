#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
int T[7][7] ;

int main(){
    cin >> n >> k ;
    rep(i,n) rep(j,k) cin >> T[i][j] ;
    bool ok = true ;
    if(n == 5) rep(i,k) rep(j,k) rep(l,k) rep(m,k) rep(o,k) if((T[0][i] ^ T[1][j] ^ T[2][l] ^ T[3][m] ^ T[4][o]) == 0) ok = false ;
    if(n == 4) rep(i,k) rep(j,k) rep(l,k) rep(m,k)          if((T[0][i] ^ T[1][j] ^ T[2][l] ^ T[3][m]) == 0)           ok = false ;
    if(n == 3) rep(i,k) rep(j,k) rep(l,k)                   if((T[0][i] ^ T[1][j] ^ T[2][l]) == 0)                     ok = false ;
    if(n == 2) rep(i,k) rep(j,k)                            if((T[0][i] ^ T[1][j]) == 0)                               ok = false ;
    if(n == 1) rep(i,k)                                     if((T[0][i]) == 0)                                         ok = false ;
    if(ok) cout << "Nothing" << endl ;
    else cout << "Found" << endl ;
}