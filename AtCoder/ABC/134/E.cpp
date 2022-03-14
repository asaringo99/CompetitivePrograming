#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[101010] ;
ll dp[101010] ;

int main(){
    cin >> n ;
    memset(dp,-1,sizeof(dp)) ;
    rep(i,n) cin >> A[i] ;
    rep(i,n){
        auto it = lower_bound(dp,dp+n,A[i]) ;
        it-- ;
        int id = it - dp ;
        dp[id] = A[i] ;
    }
    int res = 0 ;
    rep(i,n) if(dp[i] != -1) res++ ;
    cout << res << endl ;
}