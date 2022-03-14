#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , q ;

int main(){
    cin >> n >> q ;
    set<P> ta , yo ;
    ta.insert(P(0,-1)) ;
    yo.insert(P(0,-1)) ;
    ta.insert(P(n,-1)) ;
    yo.insert(P(n,-1)) ;
    ll tate = n - 2 , yoko = n - 2 ;
    ll res = (n - 2) * (n - 2) ;
    rep(i,q){
        ll x , y ;
        cin >> x >> y ;
        if(x == 1 && y == 1) continue ;
        if(x == 1){
            auto it = ta.upper_bound(P(y,-1)) ;
            it-- ;
            if(it->first == 0){
                res -= tate ;
                yoko = min(yoko,y) ;
                ta.insert(P(y,tate)) ;
            }
            else{
                res -= it->second ;
            }
        }
        if(y == 1){
            auto it = yo.upper_bound(P(x,-1)) ;
            it-- ;
            if(it->first == 0){
                res -= yoko ;
                tate = min(tate,x) ;
                yo.insert(P(x,yoko)) ;
            }
            else{
                res -= it->second ;
            }
        }
    }
    cout << res << endl ;
}