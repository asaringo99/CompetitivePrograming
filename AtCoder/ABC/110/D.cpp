#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;
const int MAX_N = 303030 ;

ll pes[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N+1] ; // (n!) (mod p) を格納

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

ll n , m ;
map<ll,ll> mp ;

int main(){
    init() ;
    cin >> n >> m ;
    for(int i = 2 ; i * i <= m ; i++){
        if(m % i != 0) continue ;
        int cnt = 0 ;
        while(m % i == 0){
            m /= i ;
            cnt++ ;
        }
        mp[i] = cnt ;
    }
    if(m != 1) mp[m]++ ;
    ll res = 1 , rec = n - 1 ;
    for(auto it : mp) (res *= combination(rec+it.second,it.second)) %= mod ;
    cout << res << endl ;
}