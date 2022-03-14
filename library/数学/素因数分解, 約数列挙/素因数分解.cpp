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

struct PrimeFactorization{
    ll n ;
    vector<P> res ;
    PrimeFactorization(ll n_){
        n = n_ ;
        build() ;
    }

    void build(){
        ll m = n ;
        for(ll i = 2 ; i * i <= m ; i++){
            if(m % i != 0) continue ;
            int ex = 0 ;
            while(m % i == 0){
                m /= i ;
                ex++ ;
            }
            res.push_back(P(i,ex)) ;
        }
        if(m != 1) res.push_back(P(m,1)) ;
    }

    vector<P> primeFactor() { return res ; }
    int origin() { return n ; }
};

int main(){
    ll n ;
    cin >> n ;
    PrimeFactorization A(n) ;
    for(P p : A.primeFactor()) cout << p.first << " " << p.second << endl ;
}