#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , k ;

const ll mod = 1777777777 ;
const int MAX_N = 1000000 ;

ll inv[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll fac[MAX_N+1] ; // (n!) (mod p) を格納

// 繰り返し二乗法
ll powmod(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void f(){
    inv[0] = 1 ; inv[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        inv[i] = powmod(i,mod-2) * inv[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void g(){
    fac[0] = 1 ; fac[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        fac[i] = (fac[i-1] * i) % mod ;
    }
}

//nCrの計算
ll combination(ll n , ll r){
    return fac[n] * inv[n-r] % mod * inv[r] % mod ;
}

void init(){ f() ; g() ; }

ll comb(ll n , ll k){
    ll fa = 1 ;
    ll in = 1 ;
    ll p = n ;
    for(int i = 0 ; i < k ; i++) {
        ll q = p ;
        q %= mod ;
        (fa *= q) %= mod ;
        p-- ;
    }
    for(int i = 1 ; i <= k ; i++) (in *= powmod(i,mod-2)) %= mod ;
    return fa * in % mod ;
}

int main(){
    init() ;
    cin >> n >> k ;
    ll res = 0 ;
    rrep(i,1,k+1){
        if(i % 2 == 1) res += combination(k,i) * fac[k-i] % mod ;
        if(i % 2 == 0) res -= combination(k,i) * fac[k-i] % mod ;
        (res += mod) %= mod ;
    }
    res = (fac[k] - res + mod) % mod ;
    (res *= comb(n,k)) %= mod ;
    cout << res << endl ;
}