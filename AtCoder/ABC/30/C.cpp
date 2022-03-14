#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
ll x , y ;
ll A[101010] , B[101010] ;

int main(){
    cin >> n >> m >> x >> y ;
    rep(i,n) cin >> A[i] ;
    rep(i,m) cin >> B[i] ;
    A[n] = 1e15 ;
    B[m] = 1e15 ;
    sort(A,A+n) ;
    sort(B,B+m) ;
    ll val = 0 ;
    int res = 0 ;
    while(true){
        auto it = lower_bound(A,A+n+1,val) ;
        if(*it == 1e15) break ;
        val = *it + x ;
        it = lower_bound(B,B+m+1,val) ;
        if(*it == 1e15) break ;
        val = *it + y ;
        res++ ;
    }
    cout << res << endl ;
}