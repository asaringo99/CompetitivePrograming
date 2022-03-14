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
        int val = 1e9+10 ;
        rep(l,n-1) rrep(r,l+1,n) {
            rrep(i,0,r-l) A[l+i] &= A[r-i] ;
            rep(i,n) val = min(val,A[i]) ;
        }
        cout << val << endl ;
    }
}