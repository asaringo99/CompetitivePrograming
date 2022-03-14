#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n , m ;
ll X[101010] , Y[101010] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> X[i] ;
    rep(i,m) cin >> Y[i] ;
    sort(X,X+n) ;
    sort(Y,Y+m) ;
    ll nx = X[0] , ny = Y[0];
    ll sx = 0 , sy = 0 ;
    ll xx = 0 , yy = 0 ;
    rrep(i,1,n){
        ll x = X[i] ;
        (xx += (x - nx) * i % mod - sx + mod) %= mod ;
        (sx += x - nx) %= mod ;
    }
    rrep(i,1,m){
        ll y = Y[i] ;
        (yy += (y - ny) * i % mod - sy + mod) %= mod ;
        (sy += y - ny) %= mod ;
    }
    cout << (xx * yy % mod) << endl ;
}