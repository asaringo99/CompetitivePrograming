#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll A[1010] , B[1010] ;
vector<ll> C[1010] ;
ll dp[1 << 20] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        cin >> A[i] >> B[i] ;
        rep(j,B[i]){
            ll c ;
            cin >> c ;
            c-- ;
            C[i].push_back(c) ;
        }
    }
    rep(i,1<<n) dp[i] = 1e16 ;
    dp[0] = 0 ;
    rep(S,1<<n){
        rep(i,m){
            int u = 0 ;
            rep(j,B[i]) u |= 1 << C[i][j] ;
            dp[S | u] = min(dp[S|u],dp[S]+A[i]) ;
        }
    }
    if(dp[(1<<n)-1] == 1e16) dp[(1<<n)-1] = -1 ;
    cout << dp[(1<<n)-1] << endl ;
}