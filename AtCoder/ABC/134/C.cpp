#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[202020] , B[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] , B[i] = A[i] ;
    sort(A,A+n) ;
    bool ok = false ;
    if(A[n-1] == A[n-2]) ok = true ;
    if(ok) rep(i,n) cout << A[n-1] << endl ;
    else rep(i,n) if(B[i] == A[n-1]) cout << A[n-2] << endl ; else cout << A[n-1] << endl ;
}