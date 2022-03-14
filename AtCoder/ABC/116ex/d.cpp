#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
vector<ll> X[101010] ;
priority_queue<ll,vector<ll>,greater<ll>> que , squ ;
set<ll> st ;


int main(){
    ll res = 0 ;
    cin >> n >> k ;
    rep(i,n){
        ll t , d ;
        cin >> t >> d ;
        st.insert(t) ;
        X[t].push_back(d) ;
        res += d ;
    }
    ll m = st.size() ;
    res += m * m ;
    for(int u : st) sort(X[u].begin(),X[u].end(),greater<ll>()) ;
    for(int u : st) rep(i,X[u].size()) {
        if(i == 0) squ.push(X[u][i]) ;
        if(i != 0) que.push(X[u][i]) ;
    }
    rep(i,n-k){
        if(que.empty()){
            ll sq = squ.top() + m * m - (m - 1) * (m - 1) ;
            res -= sq ;
            m-- ;
            squ.pop() ;
            continue ;
        }
        ll sq = squ.top() + m * m - (m - 1) * (m - 1) , qu = que.top() ;
        if(sq < qu){
            m-- ;
            res -= sq ;
            squ.pop() ;
        }
        else{
            res -= qu ;
            que.pop() ;
        }
    }
    cout << res << endl ;
}