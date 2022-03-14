#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
P A[101010] ;
set<ll> st ;

int main(){
    cin >> n >> m ;
    rep(i,n) {
        int a , b ;
        cin >> a >> b ;
        A[i] = P(b,a) ;
    }
    rrep(i,1,m+1) st.insert(i) ;
    sort(A,A+n,greater<P>()) ;
    ll res = 0 ;
    rep(i,n){
        ll b = A[i].first , a = A[i].second ;
        auto it = st.lower_bound(a) ;
        if(it == st.end()) continue ;
        res += b ;
        st.erase(it) ;
    }
    cout << res << endl ;
}