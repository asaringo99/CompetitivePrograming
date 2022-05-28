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

int n ;
ll A[55] ;
vector<ll> vec ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll digit = A[0] ;
    ll sum = A[0] ;
    int bf = 0 ;
    rrep(i,1,n){
        digit /= 10 ;
        if(digit > 0){
            (sum += powmod(10,i) * A[i] % mod * powmod(powmod(10,bf),mod-2) % mod) %= mod ;
        }
        else{
            vec.push_back(sum) ;
            sum = A[i] ;
            bf = i ;
        }
        digit += A[i] ;
    }
    if(digit > 0) vec.push_back(sum) ;
    ll res = 1 ;
    for(ll u : vec) (res *= u + 1) %= mod ;
    cout << (res - 1 + mod) % mod << endl ;
}