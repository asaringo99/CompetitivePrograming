#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , q ;
set<P> st[202020] , eq ;
P bab[202020] ;


int main(){
    cin >> n >> q ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        b-- ;
        st[b].insert(P(a,i)) ;
        bab[i] = P(b,a) ;
    }
    ll sum = 0 ;
    rep(i,200000){
        if(st[i].size() == 0) continue ;
        auto it = st[i].end() ;
        it-- ;
        eq.insert(*it) ;
    }
    rep(i,q){
        ll c , d ;
        cin >> c >> d ;
        c-- ;
        d-- ;
        {// 処理1
            int x = bab[c].first ; // x : 幼児Cの幼稚園
            ll val = bab[c].second ; // val : 幼児Cのレート
            auto it1 = st[x].end() ; it1-- ;
            eq.erase(it1) ;
            if(st[x].count(P(val,c))) st[x].erase(P(val,c)) ;
            auto it2 = st[x].end() ; it2-- ;
            eq.insert(*it2) ;
        }
        {// 処理2
            bab[c].first = d ;
            ll val = bab[c].second ;
            if(st[d].size() == 0) {
                eq.insert(P(val,c)) ;
                st[d].insert(P(val,c)) ;
            }
            else{
                auto it1 = st[d].end() ; it1-- ;
                eq.erase(it1) ;
                st[d].insert(P(val,c)) ;
                auto it2 = st[d].end() ; it2-- ;
                eq.insert(*(it2)) ;
            }
        }
        auto it = eq.begin() ;
        // cout << (it->first) << endl ;
    }
}