#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define MAX_N (ll)2e5

int n ;

int main(){
    cin >> n ;
    ll A[n] ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    ll S[n+1] ;
    S[0] = 0 ;
    rep(i,n) S[i+1] = S[i] + A[i] ;
    ll ans = 0 ;
    for(int i = 1 ; i < n ; i++){
        ans += i * A[i] - S[i] ;
    }
    cout << ans << endl ;
}