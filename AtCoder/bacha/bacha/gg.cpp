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

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= 3 ;
        (x *= x) %= 3 ;
        n >>= 1 ;
    }
    return res ;
}

struct FastPrimeFactorization{

    private :
        int n ;
        vector<int> factor ;
        vector<int> prime ;
        vector<bool> isprime;

        void build(){
            for(int i = 2 ; i < n ; i++){
                if(factor[i] != -1) continue ;
                for(int j = i ; j < n ; j += i) factor[j] = i ;
                prime.push_back(i) ;
                isprime[i] = true ;
            }
        }
        
    public :

        FastPrimeFactorization(int n_){
            n = max(n_,404040) ;
            factor.resize(n,-1) ;
            isprime.resize(n,false) ;
            build() ;
        }

        // 素因数分解 20 -> { (5,1), (2,2) }
        vector<P> primeFactorization(int k){
            vector<P> res ;
            while(k != 1){
                int ex = 0 ;
                int d = factor[k] ;
                while(k % d == 0){
                    k /= d ;
                    ex++ ;
                }
                res.push_back(P(d,ex)) ;
            }
            return res ;
        }

        // 素因数分解の素因数のみ 20 -> { 5, 2 }
        vector<int> primeFactor(int k){
            vector<int> res ;
            while(k != 1){
                int ex = 0 ;
                int d = factor[k] ;
                while(k % d == 0){
                    k /= d ;
                    ex++ ;
                }
                res.push_back(d) ;
            }
            return res ;
        }
};

int n ;
vector<vector<P>> vec ;
vector<vector<P>> prime ;
int mp[5] ;

int main(){
    // fast_input_output
    FastPrimeFactorization fpf(n+10);
    cin >> n ;
    ll sum = 0 ;
    prime.push_back({}) ;
    rrep(i,1,n){
        prime.push_back(fpf.primeFactorization(i)) ;
    }
    rep(i,n){
        ll comb = 1 ;
        if(i != 0 && i != n - 1){
            for(P p : prime[n-i]){
                mp[p.first%3] += p.second ;
            }
            for(P p : prime[i]){
                mp[p.first%3] -= p.second ;
            }
            for(int u : {0,1,2}) {
                if(mp[u] == 0) continue;
                comb *= powmod(u,mp[u]) ;
                comb %= 3 ;
            }
        }
        char a ;
        cin >> a ;
        if(a == 'W') sum += 0 * comb ;
        if(a == 'R') sum += 1 * comb ;
        if(a == 'B') sum += 2 * comb ;
        sum %= 3 ;
    }
    int res = n % 2 == 1 ? sum : (3 - sum) % 3 ;
    if(res == 0) cout << 'W' << endl ;
    if(res == 1) cout << 'R' << endl ;
    if(res == 2) cout << 'B' << endl ;
}