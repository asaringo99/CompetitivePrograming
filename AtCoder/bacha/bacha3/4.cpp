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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
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
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r] % mod * inv[r] % mod ;
}

ll permutation(ll n , ll r){
    if(n < 0 || r < 0 || n < r) return 0 ;
    return fac[n] * inv[n-r] % mod ;
}

void init(){ f() ; g() ; }

int n , m ;
vector<P> A , B ;
set<int> H , W ;
map<int,int> mp ;

int main(){
    fast_input_output
    init() ;
    cin >> n >> m ;
    A.resize(n) ;
    B.resize(m) ;
    rep(i,n) cin >> A[i].first , A[i].second = i , mp[A[i].first]++ ;
    rep(i,m) cin >> B[i].first , B[i].second = i , mp[B[i].first]++ ;
    rrep(i,1,n*m+1) if(mp[i] > 2) {
        cout << 0 << endl ;
        return 0 ;
    }
    A.push_back(P(-1,-1)) ;
    B.push_back(P(-1,-1)) ;
    sort(A.begin(),A.end()) ;
    sort(B.begin(),B.end()) ;
    ll res = 1 ;
    bool first = true ;
    int val = n * m ;
    ll cross = 0 ;
    while(true){
        if(val == 0) break ;
        int s = A.size() - 1 ;
        int t = B.size() - 1 ;
        auto [a,x] = A[s] ;
        auto [b,y] = B[t] ;
        if(first){
            if(a != val || b != val){
                cout << 0 << endl ;
                return 0 ;
            }
            H.insert(x) ;
            W.insert(y) ;
            A.pop_back() ;
            B.pop_back() ;
            val-- ;
            first = false ;
        }
        else{
            if(a == val && b == val){
                cross += (ll)H.size() + (ll)W.size() ;
                H.insert(x) ;
                W.insert(y) ;
                A.pop_back() ;
                B.pop_back() ;
                val-- ;
            }
            else if(a == val){
                cross += (ll)W.size() - 1 ;
                H.insert(x) ;
                A.pop_back() ;
                res *= (ll)W.size() ;
                res %= mod ;
                val-- ;
            }
            else if(b == val){
                cross += (ll)H.size() - 1 ;
                W.insert(y) ;
                B.pop_back() ;
                res *= (ll)H.size() ;
                res %= mod ;
                val-- ;
            }
            else{
                res *= cross ;
                res %= mod ;
                cross-- ;
                val-- ;
            }
        }
    }
    cout << res << endl ;
}