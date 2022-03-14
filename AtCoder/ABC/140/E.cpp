#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define MAX_N 1000

int n ;

int main(){
    cin >> n ;
    pair<ll,int> P[n] ;
    rep(i,n){
        int p ;
        cin >> p ;
        pair<ll,int> pir(p,i) ;
        P[i] = pir ;
    }
    sort(P,P+n,greater<pair<ll,int>>()) ;
    set<int> S ;
    S.insert(-1) ;
    S.insert(n) ;
    ll res = 0 ;
    rep(i,n){
        auto it = S.lower_bound(P[i].second) ;
        ll l1 = -1 , l2 = -1 , r1 = n , r2 = n ;
        if(*it != n){
            it++ ;
            r2 = *it ;
            it-- ;
        }
        r1 = *it ;
        it-- ;
        if(*it != -1){
            l1 = *it ;
            it-- ;
        }
        l2 = *it ;
        res += P[i].first * ( (l1 - l2) * (r1 - P[i].second) + (r2 - r1) * (P[i].second - l1) ) ;
        S.insert(P[i].second) ;
    }
    cout << res << endl ;
}