#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int A , B , Q ;

int main(){
    cin >> A >> B >> Q ;
    set<ll> S , T ;
    S.insert((ll)-1e15) ;
    S.insert((ll)1e15) ;
    T.insert((ll)-1e15) ;
    T.insert((ll)1e15) ;
    for(int i = 0 ; i < A ; i++){
        ll a ;
        cin >> a ;
        S.insert(a) ;
    }
    for(int i = 0 ; i < B ; i++){
        ll b ;
        cin >> b ;
        T.insert(b) ;
    }
    for(int i = 0 ; i < Q ; i++){
        ll x ;
        cin >> x ;
        auto st1 = S.upper_bound(x) ;
        auto tt1 = T.upper_bound(x) ;
        auto st2 = S.upper_bound(x) ;
        auto tt2 = T.upper_bound(x) ;
        st1-- ; tt1-- ;
        ll res = LLONG_MAX ;
        res = min(res,min(abs(x-*st1),abs(x-*tt1))+abs(*st1-*tt1)) ;
        res = min(res,min(abs(x-*st1),abs(x-*tt2))+abs(*st1-*tt2)) ;
        res = min(res,min(abs(x-*st2),abs(x-*tt1))+abs(*st2-*tt1)) ;
        res = min(res,min(abs(x-*st2),abs(x-*tt2))+abs(*st2-*tt2)) ;
        cout << res << endl ;
    }
}