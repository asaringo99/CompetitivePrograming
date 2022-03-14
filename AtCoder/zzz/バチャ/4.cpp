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

ll n , m , k , a , b ;
char T[20][505] ;
char X[20][505] ;

bool f(ll x , ll s){
    rep(i,n){
        ll cnt = 0 ;
        rep(j,m){
            if(X[j][i] == 'o') cnt++ ;
        }
        ll c = cnt - x ;
        if(c > 0) s -= c * a ;
    }
    return s >= 0 ;
}

int main(){
    cin >> n >> m >> k >> a >> b ;
    rep(i,m) rep(j,n) cin >> T[i][j] ;
    ll res = 30 ;
    rep(S,1<<m){
        ll sum = k ;
        rep(i,m) rep(j,n) X[i][j] = T[i][j] ;
        rep(i,m) if(S >> i & 1){
            sum -= b ;
            rep(j,n) X[i][j] = 'x' ;
        }
        if(sum < 0) continue ;
        ll lef = 0 ,  rig = 20 ;
        while(rig - lef > 0){
            ll mid = (lef + rig) / 2 ;
            if(f(mid,sum)) rig = mid ;
            else lef = mid + 1 ;
        }
        chmin(res,rig) ;
    }
    cout << res << endl ;
}