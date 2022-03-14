#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
ll A[101010] ;

int main(){
    cin >> n >> k ;
    bool ok = false ;
    rep(i,n){
        ll a ;
        cin >> a ;
        if(a == 0) ok = true ;
        A[i] = a ;
    }
    if(ok){
        cout << n << endl ;
        return 0 ;
    }
    if(k == 0){
        cout << 0 << endl ;
        return 0 ;
    }
    int l = 0 , r = 0 , res = 0 ;
    ll pro = 1 ;
    while(r < n){
        while(r < n && pro <= k){
            res = max(res,r-l) ;
            pro *= A[r] ;
            r++ ;
        }
        while(pro > k){
            pro /= A[l] ;
            l++ ;
        }
        res = max(res,r-l) ;
    }
    cout << res << endl ;
}