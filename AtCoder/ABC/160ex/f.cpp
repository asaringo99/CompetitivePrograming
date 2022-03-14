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

const int mod = 1000000007 ;
const int MAX_N = 303030 ;

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
    return fac[n] * inv[r] % mod ;
}

void init(){ f() ; g() ; }

int n ;
vector<int> G[202020] ;
ll dp[202020] , ans[202020] ;
ll d[202020] ;

void dfs(int v , int prev){
    ll sum = 0 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
        sum += d[u] ;
    }
    d[v] = sum + 1 ;
    ll res = 1 ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        res *= combination(sum,d[u]) * dp[u] % mod ;
        res %= mod ;
        sum -= d[u] ;
    }
    dp[v] = res ;
}

void rec(int v , int prev){
    if(v == 0) ans[v] = dp[v] ;
    else{
        ll com = combination(n-1,d[v]) * dp[v] % mod ;
        ll res = ans[prev] * powmod(com,mod-2) % mod ;
        ll sum = n - 1 ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(u == prev) continue ;
            res *= combination(sum,d[u]) % mod * dp[u] % mod ;
            res %= mod ;
            sum -= d[u] ;
        }
        ans[v] = res ;
    }
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        rec(u,v) ;
    }
}

int main(){
    init() ;
    cin >> n ;
    rep(i,n-1){
        int a, b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    rec(0,-1) ;
    rep(i,n) cout << ans[i] << endl ;
}