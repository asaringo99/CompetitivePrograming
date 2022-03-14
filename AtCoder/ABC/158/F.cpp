#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;

int n ;
P X[202020] ;
set<ll> st ;
map<ll,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i].first >> X[i].second ;
    sort(X,X+n) ;
    st.insert(1e17) ;
    st.insert(-1e17) ;
    mp[1e17] = 1 ;
    rep(i,n){
        ll x = X[n-1-i].first , d = X[n-1-i].second ;
        auto it = st.upper_bound(x+d-1) ;
        it-- ;
        ll pls = *it ;
        if(pls == -1e17){
            it++ ;
            mp[x] = mp[*it] * 2 ;
            st.insert(x) ;
        }
        else{
            it++ ;
            mp[x] += mp[*it] ;
            mp[x] += mp[X[n-i].first] ;
            it-- ;
            while(it != st.begin()) st.erase(it--) ;
            st.insert(x) ;
        }
        mp[x] %= mod ;
    }
    cout << mp[X[0].first] << endl ;
}