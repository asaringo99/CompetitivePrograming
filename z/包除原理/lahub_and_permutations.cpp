#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

const int mod = 1000000007 ;
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

int n ;
ll A[2020] ;
set<int> st ;

int main(){
    fast_input_output
    init() ;
    cin >> n ;
    ll cnt = 0 , emp = 0 ;
    rep(i,n) {
        cin >> A[i] ;
        if(A[i] == -1) emp++ ;
        else st.insert(A[i]) ;
    }
    rep(i,n) if(A[i] == -1){
        if(st.count(i+1) == 0) cnt++ ;
    }
    ll sum = 0 ;
    rrep(i,1,cnt+1){
        if(i % 2 == 1) sum += combination(cnt,i) * permutation(emp-i,emp-i) % mod ;
        if(i % 2 == 0) sum -= combination(cnt,i) * permutation(emp-i,emp-i) % mod ;
        (sum += mod) %= mod ;
    }
    ll res = (permutation(emp,emp) - sum + mod) % mod ;
    cout << res << endl ;
}