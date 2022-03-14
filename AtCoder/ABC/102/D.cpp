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

int n ;

int main(){
    cin >> n ;
    ll S[n+1] ;
    S[0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        ll a ;
        cin >> a ;
        S[i+1] = S[i] + a ;
    }
    ll res = LLONG_MAX ;
    for(int i = 2 ; i <= n - 2 ; i++){
        auto it = upper_bound(S+1,S+i+1,S[i]/2) ;
        ll l = *it ;
        it-- ;
        ll m = *it ;
        ll p = l , q = S[i] - l ;
        if(abs(S[i] - l * 2) > abs(S[i] - m * 2)){
            p = m ;
            q = S[i] - m ;
        }
        it = upper_bound(S+i+1,S+n+1,(S[n]-S[i])/2+S[i]) ;
        ll x = *it - S[i] ;
        it-- ;
        ll y = *it - S[i] ;
        ll r = x , s = S[n] - S[i] - x ;
        if(abs(S[n] - S[i] - x * 2) > abs(S[n] - S[i] - y * 2)){
            r = y ;
            s = S[n] - S[i] - y ;
        }
        res = min(res,max(max(p,q),max(r,s))-min(min(p,q),min(r,s))) ;
    }
    cout << res << endl ;
}