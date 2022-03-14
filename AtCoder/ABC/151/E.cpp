#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
const int MAX_N = 2000007 ;

int n , k ;
ll A[101010] ;
ll pes[MAX_N] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N] ; // (n!) (mod p) を格納

// 逆元(1/n)のmod計算
ll invmodcal(ll A , ll N){
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
        pes[i] = invmodcal(i,mod-2) * pes[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void powmod(){
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
    powmod() ;
    invmod() ;
}


int main(){
    init() ;
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    ll res = 0 ;
    rep(i,n){
        if(i - k + 1 >= 0) res = (res + combination(i,k-1) * A[i] + mod) % mod ;
        if(i + k <= n) res = (res - combination(n-1-i,k-1) * A[i] + mod) % mod ;
    }
    cout << res << endl ;
}