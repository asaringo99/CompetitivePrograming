#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int main(){
    cin >> t ;
    rep(z,t){
        int n ;
        int A[110] ;
        memset(A,0,sizeof(A)) ;
        cin >> n ;
        rep(i,n) cin >> A[i] ;
        int res = 1e9+10 ;
        rep(l,n) rep(r,n) A[l] &= A[r] ;
        int val = -1 ;
        rep(i,n) val = max(val,A[i]) ;
        res = min(val,res) ;
        cout << res << endl ;
    }
}