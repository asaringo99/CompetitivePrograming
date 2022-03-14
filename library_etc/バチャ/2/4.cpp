#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int H , W ;
ll C[10][10] , A[202][202] ;

void f(){
    rep(k,10) rep(i,10) rep(j,10) chmin(C[i][j],C[i][k]+C[k][j]) ;
}

int main(){
    cin >> H >> W ;
    rep(i,10) rep(j,10) cin >> C[i][j] ;
    f() ;
    ll sum = 0 ;
    rep(i,H) rep(j,W){
        ll a ;
        cin >> a ;
        if(a == -1) continue ;
        sum += C[a][1] ;
    }
    cout << sum << endl ;
}