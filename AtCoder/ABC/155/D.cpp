#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , k ;
ll A[202020] ;

ll f(ll x){
    ll count = 0 ;
    rep(i,n){
        if(A[i] == 0){
            if(x >= 0) count += n - i - 1 ;
            continue ;
        }
        ll val = x / A[i] ;
        if(x % A[i] != 0){
            if(x < 0 && A[i] < 0) val++ ;
        }
        auto it = lower_bound(A+i,A+n,val) ;
        if(A[i] > 0){
            ll id = it - (A+i) ;
            count += id ;
        }
        if(A[i] < 0){
            ll id = it - A ;
            count += min(n-id,n-i-1) ;
        }
    }
    return count ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    ll lef = -1e18 , rig = 1e18 ; 
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        cout << lef << " " << rig << " " << mid << " " << f(mid) << endl ;
        if(f(mid) >= k) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}