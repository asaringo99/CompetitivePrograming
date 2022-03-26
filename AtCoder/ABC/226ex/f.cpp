#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 998244353 ;
const int MAX_N = 505050 ;

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

ll permutation(ll n , ll r){
    return fac[n] * inv[n-r] % mod ;
}

void init(){ f() ; g() ; }

int n , x ;

ll dp[55][55][55] ;

int main(){
    init() ;
    cin >> n >> x ;
    rrep(i,1,n+1) {
        dp[i][i][1] = combination(n,i) * permutation(i-1,i-1) % mod ;
        rrep(j,1,n+1) rrep(k,1,n+1){
            rrep(a,1,n){
                if(i + a > n) break ;
                (dp[i+a][max(a,j)][k+1] += dp[i][j][k] * combination(n-i,a) % mod * permutation(a-1,a-1) % mod) %= mod ;
            }
        }
    }
    ll res = 0 ;
    rrep(i,1,n+1) rrep(j,1,n+1) {
        ll val = dp[n][i][j] * powmod(permutation(j,j),mod-2) % mod ;
        (res += powmod(i,x) * val % mod) %= mod ;
    }
    cout << res << endl ;
}