#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
int n ;
ll A[202020] , B[202020] ;
map<P,ll> mp ;
map<P,bool> used ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

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
    cin >> n ;
    rep(i,n) cin >> A[i] >> B[i] ;
    ll zero = 0 ;
    rep(i,n){
        ll g = gcd(A[i],B[i]) ;
        if(g == 0) {
            zero++ ;
            continue ;
        }
        ll a = A[i] / g , b = B[i] / g ;
        mp[P(a,b)]++ ;
    }
    ll res = 1 ;
    for(auto it : mp){
        ll x = it.first.first , y = it.first.second ;
        if(used[P(x,y)] || used[P(-x,-y)] || used[P(-y,x)] || used[P(y,-x)]) continue ;
        used[P(x,y)] = used[P(-x,-y)] = used[P(-y,x)] = used[P(y,-x)] = true ;
        ll p = mp[P(x,y)] + mp[P(-x,-y)] , q = mp[P(-y,x)] + mp[P(y,-x)] ;
        ll val = (powmod(2,p) + powmod(2,q) - 1 + mod) % mod ;
        (res *= val) %= mod ;
    }
    cout << (res - 1 + zero + mod) % mod << endl ;
}