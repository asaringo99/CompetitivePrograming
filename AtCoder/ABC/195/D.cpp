#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n , m , Q ;

int main(){
    cin >> n >> m >> Q ;
    ll X[m] ;
    P W[n] ;
    for(int i = 0 ; i < n ; i++) {
        cin >> W[i].second >> W[i].first ;
    }
    for(int i = 0 ; i < m ; i++) cin >> X[i] ;
    sort(W,W+n,greater<P>()) ;
    vector<ll> ans ;
    for(int i = 0 ; i < Q ; i++){
        multiset<ll> S ;
        int lef , rig ;
        cin >> lef >> rig ;
        rig-- ; lef-- ;
        for(int j = 0 ; j < m ; j++){
            if(rig < j || j < lef){
                S.insert(X[j]) ;
            }
        }
        ll res = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(S.empty()) break ;
            auto it = S.lower_bound(W[j].second) ;
            if(it == S.end()) continue ;
            res += W[j].first ;
            S.erase(it++) ;
        }
        ans.push_back(res) ;
    }
    for(ll u : ans) cout << u << endl ;
}