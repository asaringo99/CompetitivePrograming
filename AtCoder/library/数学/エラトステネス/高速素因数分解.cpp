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

struct Eratosthenes{
    int n ;
    vector<int> factor ;

    Eratosthenes(int n_){
        n = max(n_,303030) ;
        factor.resize(n,-1) ;
        build() ;
    }

    void build(){
        for(int i = 2 ; i < n ; i++){
            if(factor[i] != -1) continue ;
            for(int j = i ; j < n ; j += i) factor[j] = i ;
        }
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

int main(){
    int n , k;
    cin >> n >> k ;
    Eratosthenes A(n) ;
    for(int p : A.primeFactor(k)) cout << p << endl ;
}