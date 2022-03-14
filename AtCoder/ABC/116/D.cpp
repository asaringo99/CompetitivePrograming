#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
P td[101010] ;
set<int> st ;
priority_queue<ll,vector<ll>,greater<ll>> que ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> td[i].second >> td[i].first ;
    sort(td,td+n,greater<P>()) ;
    ll sum = 0 ;
    rep(i,k){
        if(st.count(td[i].second) == 1) que.push(td[i].first) ;
        st.insert(td[i].second) ;
        sum += td[i].first ;
    }
    ll kind = st.size() ;
    sum += (kind * kind) ;
    ll res = sum ;
    rrep(i,k,n){
        if(st.count(td[i].second) == 1) continue ;
        if(que.empty()) continue ;
        ll val = que.top() ; que.pop() ;
        sum -= val + kind * kind ;
        kind++ ;
        sum += td[i].first + kind * kind ;
        res = max(res,sum) ;
        st.insert(td[i].second) ;
    }
    cout << res << endl ;
}