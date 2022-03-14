#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int r , c , k ;
char A[600][600] ;
int S[600][600] ;

int main(){
    cin >> r >> c >> k ;
    rep(i,r) rep(j,c) cin >> A[i][j] ;
    rep(i,r) rep(j,c) S[i+1][j+1] = S[i+1][j] + (A[i][j] == 'o' ? 1 : 0) ;
    int res = 0 ;
    rrep(i,k,r-k+2) rrep(j,k,c-k+2){
        bool ok = true ;
        rep(x,k){
            if(S[i+x][j+(k-x)-1]-S[i+x][j-(k-x)] != 2*(k-x)-1) ok = false ;
            if(S[i-x][j+(k-x)-1]-S[i-x][j-(k-x)] != 2*(k-x)-1) ok = false ;
        }
        if(ok) res++ ;
    }
    cout << res << endl ;
}