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

ll powll(ll x , ll n){
    if(n < 0) return 0 ;
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int n ;
ll x ;
ll A[101010] , B[101010] ;

int main(){
    fast_input_output
    cin >> n >> x ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    ll res = 1e18 ;
    ll minv = 1e18 , maxv = 0 ;
    rep(z,60) rep(k,min(n,50)){
        ll maxval = A[n-k-1] * (1LL << z) ;
        if(maxval > 1e16) break ;
        rep(i,n){
            ll a = A[i] ;
            if(a > maxval) B[i] = a ;
            else{
                int count = 0 ;
                while(a * 2 < maxval){
                    a *= 2 ;
                    count++ ;
                }
                ll b = 2 * a ;
                ll pl = powll(2,count) - 1 ;
                a = a + pl * x >= maxval ? maxval : a + pl * x ;
                B[i] = abs(maxval - a) < abs(maxval - b) ? a : b ;
            }
            chmin(minv,B[i]) ;
            chmax(maxv,B[i]) ;
        }
        if(maxv - minv < x) res = 0 ;
        chmin(res,maxv-minv) ;
    }
    cout << res << endl ;
}