#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , p ;
string S ;
map<ll,ll> mp ;

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= p ;
        (x *= x) %= p ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n >> p >> S ;
    ll res = 0 ;
    if(p == 2){
        rep(i,n) if((S[i] - '0') % 2 == 0) res += i + 1 ;
        cout << res << endl ;
        return 0 ;
    }
    if(p == 5){
        rep(i,n) if((S[i] - '0') % 5 == 0) res += i + 1 ;
        cout << res << endl ;
        return 0 ;
    }
    mp[0]++ ;
    ll sum = 0 ;
    rep(i,n){
        (sum += (ll)(S[n-1-i] - '0') * powll(10,i) % p) %= p ;
        res += mp[sum] ;
        mp[sum]++ ;
    }
    cout << res << endl ;
}