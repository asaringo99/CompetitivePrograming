#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<ll,ll,ll> TP ;
#define MAX_N (ll)2e5
#define INF (ll)5e17
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n ;
ll k ;
TP H[MAX_N] ;

bool cal(ll m){
    ll res = 0 ;
    rep(i,n){
        ll a , f , val ;
        tie(val,a,f) = H[i] ;
        if(a - m / f > 0) res += a - m / f ;
    }
    if(res > k) return false ;
    else return true ;
}

int main(){
    cin >> n >> k ;
    ll A[n] , F[n] ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> F[i] ;
    sort(A,A+n) ;
    sort(F,F+n,greater<ll>()) ;

    rep(i,n){
        ll val = A[i] * F[i] ;
        H[i] = tie(val,A[i],F[i]) ;
    }
    ll lef = 0 , rig = INF ;
    while(rig - lef > 0){
        ll m = (rig + lef) / 2 ;
        if(cal(m)) rig = m ;
        else lef = m + 1 ;
    }
    cout << rig << endl ;
}