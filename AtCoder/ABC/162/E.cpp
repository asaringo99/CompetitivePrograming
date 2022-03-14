#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll tes[101010] ;

int n , k ;

int main(){
    cin >> n >> k ;
    ll res = 0 ;
    for(int i = k ; i > 0 ; i--){
        ll x = k / i ;
        ll tmp = (powmod(x,n) - tes[i] + mod) % mod ;
        ll p = i ;
        for(int j = 1 ; j * j <= p ; j++){
            if(p % j == 0){
                (tes[j] += tmp) %= mod ;
                if(j * j != p) (tes[p/j] += tmp) %= mod ;
            }
        }
        ll val = tmp * i % mod ;
        (res += val) %= mod ;
    }
    cout << res << endl ;
}