#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , a , b ;
ll H[101010] , S[101010] ;

bool f(ll x){
    ll v = a - b ;
    ll sum = 0 ;
    rep(i,n) S[i] = H[i] ;
    rep(i,n) S[i] -= b * x ;
    rep(i,n) if(S[i] > 0) sum += S[i] % v == 0 ? S[i] / v : S[i] / v + 1 ;
    return sum <= x ;
}

int main(){
    cin >> n >> a >> b ;
    rep(i,n) cin >> H[i] ;
    ll lef = 0 , rig = 1e10 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}