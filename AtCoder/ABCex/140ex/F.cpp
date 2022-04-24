#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n_ , n ;
ll A[1 << 20] ;
ll node[2 * (1 << 18) + 10] ;
multiset<ll> st ;

int main(){
    cin >> n ;
    n = 1 << n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        st.insert(a) ;
    }
    st.insert(-1) ;
    st.insert(-2) ;
    auto it = st.end() ;
    it-- ;
    ll maxs = *it ;
    st.erase(it) ;
    node[0] = maxs ;
    rep(i,n-1){
        auto it = st.lower_bound(node[i]) ;
        it-- ;
        if(*it < 0){
            cout << "No" << endl ;
            return 0 ;
        }
        node[2*i+1] = node[i] ;
        node[2*i+2] = *it ;
        st.erase(it) ;
    }
    cout << "Yes" << endl ;
}