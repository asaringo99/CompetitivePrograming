#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int T ;

ll cal(ll x , ll n , ll mod){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res = (res * x) % mod ;
        x = x * x % mod ;
        n >>= 1 ;
    }
    return res % mod ;
}

ll extgcd(ll a , ll b , ll &x , ll &y){
    ll d = a ;
    if(b != 0){
        d = extgcd(b , a % b , y , x) ; // y -> x , x -> y なる変換が発生
        y -= (a / b) * x ;
    }
    else {
        x = 1 ; y = 0 ;
    }
    return d ;
}

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> T ;
    vector<ll> res ;
    for(int i = 0 ; i < T ; i++){
        ll n , s , k , x , y ;
        cin >> n >> s >> k ;
        ll tmp = extgcd(n,k,x,y) ;
        if(s % tmp == 0){
            n /= tmp ;
            s /= tmp ;
            k /= tmp ;
            ll pes = cal(k,n-2,n) ;
            y = (-s % n * pes * s + n + n + n) % n ;
        }
        else y = -1 ;
        res.push_back(y) ;
    }
    for(ll u : res) cout << u << endl ;
}