#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;
const int MAX_N = 303030 ;

ll pes[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N+1] ; // (n!) (mod p) を格納

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
void invmod(){
    pes[0] = 1 ; pes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        pes[i] = powmod(i,mod-2) * pes[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void facmod(){
    tes[0] = 1 ; tes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        tes[i] = (tes[i-1] * i) % mod ;
    }
}

//nCrの計算
ll combination(ll n , ll r){
    return tes[n] * pes[n-r] % mod * pes[r] % mod ;
}

void init(){
    invmod() ;
    facmod() ;
}

int n , m , k ;

int main(){
    init() ;
    ll res = 0 ;
    cin >> n >> m >> k ;
    rep(i,k+1) (res += m * powmod(m-1,n-i-1) % mod * combination(n-1,i) % mod) %= mod ;
    cout << res << endl ;
}