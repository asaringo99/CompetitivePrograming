#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll a , b ;
ll h[101010] , g[101010] ;

bool f(ll x){
    memset(g,0,sizeof(g)) ;
    ll p = x * b , q = a - b ;
    rep(i,n) g[i] = h[i] ;
    rep(i,n) g[i] -= p ;
    ll sum = 0 ;
    rep(i,n) if(g[i] > 0){
        ll tmp = g[i] / q ;
        if(g[i] % q != 0) tmp++ ;
        sum += tmp ;
    }
    return sum <= x ;
}

int main(){
    cin >> n >> a >> b ;
    rep(i,n) cin >> h[i] ;
    sort(h,h+n) ;
    ll lef = 0 , rig = 1e9+1 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}