#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
P X[100] ;

int main(){
    cin >> n >> k ;
    rep(i,n){
        ll x , y ;
        cin >> x >> y ;
        X[i] = P(x,y) ;
    }
    sort(X,X+n) ;
    ll res = 4e18 + 10 ;
    rep(xi,n) rep(xj,n) rep(yi,n) rep(yj,n){
        ll sx = X[xi].first , gx = X[xj].first , sy = X[yi].second , gy = X[yj].second ;
        int sum = 0 ;
        rep(i,n) if(sx <= X[i].first && X[i].first <= gx && sy <= X[i].second && X[i].second <= gy) sum++ ;
        if(sum >= k) res = min(res,abs((sx-gx)*(sy-gy))) ;
    }
    cout << res << endl ;
}