#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
set<int> st ;
P p[100007] ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        p[i] = P(a,i) ;
    }
    sort(p,p+n,greater<P>()) ;
    st.insert(-1) ;
    st.insert(n) ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        auto it = st.lower_bound(p[i].second) ;
        ll lef1 = -1 , lef2 = -1 , rig1 = *it , rig2 = *it , now = p[i].second ;
        if(*it != n){
            it++ ;
            rig1 = *it ;
            it-- ;
        }
        it-- ;
        lef1 = *it ;
        if(*it != -1){
            it-- ;
            lef2 = *it ;
        }
        res += p[i].first * ((rig1 - rig2) * (now - lef1) + (rig2 - now) * (lef1 - lef2)) ;
        st.insert(p[i].second) ;
    }
    cout << res << endl ;
}