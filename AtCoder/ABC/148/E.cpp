#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n ;

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n ;
    if(n % 2 == 1){
        cout << 0 << endl ;
        return 0 ;
    }
    ll res = 0 ;
    for(int i = 1 ; 2 * powll(5,i) <= n ; i++) res += n / (2 * powll(5,i)) ;
    cout << res << endl ;
}