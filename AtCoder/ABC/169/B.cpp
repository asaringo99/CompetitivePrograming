#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
    cin >> n ;
    ll val = 1e18 , res = 1 ;
    bool ok = false ;
    ll A[n] ;
    for(int i = 0 ; i < n ; i++) {
        cin >> A[i] ;
        if(A[i] == 0){
            cout << 0 << endl ;
            return 0 ;
        }
    }

    for(int i = 0 ; i < n ; i++){
        ll a ;
        a = A[i] ;
        val /= a ;
        if(val == 0){
            cout << -1 << endl ;
            return 0 ;
        }
        res *= a ;
    }
    cout << res << endl ;
}