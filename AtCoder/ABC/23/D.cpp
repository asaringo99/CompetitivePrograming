#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll H[101010] , S[101010] ;

bool f(ll x){
    vector<ll> Y ;
    rep(i,n){
        if(x - H[i] < 0) return false ;
        Y.push_back((x - H[i]) / S[i]) ;
    }
    sort(Y.begin(),Y.end()) ;
    rep(i,n) if(i > Y[i]) return false ;
    return true ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> H[i] >> S[i] ;
    ll lef = 0 , rig = 1e18 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}