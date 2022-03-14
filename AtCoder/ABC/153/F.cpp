#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , d , a ;
P X[202020] ;

int main(){
    cin >> n >> d >> a ;
    rep(i,n) cin >> X[i].first >> X[i].second ;
    sort(X,X+n) ;
    set<P> st ;
    st.insert(P(1e17,0)) ;
    ll pls = 0 , res = 0 ;
    rep(i,n){
        ll x = X[i].first , h = X[i].second ;
        auto it = st.begin() ;
        while(it->first < x){
            pls -= it->second ;
            st.erase(it++) ; 
        }
        h -= pls ;
        if(h < 0) continue ;
        ll tmp = h / a ;
        if(h % a != 0) tmp++ ;
        res += tmp ;
        pls += tmp * a ;
        st.insert(P(x+2*d,tmp*a)) ;
    }
    cout << res << endl ;
}