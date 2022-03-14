#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll a , b , c ;
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

int main(){
    cin >> a >> b >> c ;
    ll X = b * powmod(a,mod-2) % mod ;
    ll Y = c * powmod(a,mod-2) % mod ;
    ll row = ((1 - Y + mod) % mod - (X - 1 + mod) % mod * (Y - 1 + mod) % mod + mod) % mod ;
    ll key = (X - 1 + mod) % mod * (Y - 1 + mod) % mod ;
    key = (key - 1 + mod) % mod ;
    row = row * powmod(key,mod-2) % mod ;
    ll col = (X - 1 + mod) % mod * (row + 1) % mod ;
    cout << col << " " << row << endl ;
}