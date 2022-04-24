#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
P X[101010] ;

int main(){
    cin >> n ;
    rep(i,n){
        int x ;
        cin >> x ;
        X[i] = P(x,i) ;
    }
    set<ll> st ;
    sort(X,X+n,greater<P>()) ;
    st.insert(-1) ;
    st.insert(n) ;
    ll res = 0 ;
    rep(i,n){
        ll val = X[i].first , id = X[i].second ;
        ll l = -1 , r = n ;
        ll x = -1 , y = n ;
        auto it = st.lower_bound(id) ;
        if(*it != n){
            y = *it ; it++ ;
            r = *it ; it-- ;
        }
        it-- ;
        if(*it != -1){
            x = *it ; it-- ;
            l = *it ;
        }
        st.insert(id) ;
        res += (r - y) * (id - x) * val ;
        res += (x - l) * (y - id) * val ;
    }
    cout << res << endl ;
}