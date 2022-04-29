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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

ll powmod(ll x , ll n , ll mod){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

int t ;

ll f(ll n , ll a , ll b , ll x , ll y , ll z){
    ll cnt_a = n / a , cost_a = n / a * y ;
    ll m = n - n / a * a ;
    ll cnt_b = m / b , cost_b = m / b * z ;
    ll cost_c = (m - m / b * b) * x ;
    return cost_a + cost_b + cost_c ;
}

ll g(ll n , ll a , ll b , ll x , ll y , ll z){
    ll cnt_b = n / b , cost_a = n / b * z ;
    ll m = n - n / b * b ;
    ll cnt_a = m / a , cost_b = m / a * y ;
    ll cost_c = (m - m / a * a) * x ;
    return cost_a + cost_b + cost_c ;
}

ll h(ll n , ll a , ll b , ll x , ll y , ll z , ll val , ll g){
    if(val > n) return 1e18 ;
    ll cost_c = x * (n - val) ;
    n = val ;
    n /= g ;
    a /= g ;
    b /= g ;
    ll m = n ;
    ll res = 1e18 ;

    ll aa = a % b ;
    m %= b ;
    cout << m << endl ;
    cout << powmod(aa,b-2,b) << endl ;
    (m *= powmod(aa,b-2,b)) %= b ;
    ll cost_a = m * y ;
    ll cost_b = (n - a * m) / b * z ;
    if(cost_b >= 0) chmin(res,cost_a+cost_b+cost_c) ;
    if(cost_a + cost_b + cost_c == 421032) cout << a << " " << b << " " << m << " " << n - a * m << " " << n << endl ;

    m = n ;
    ll bb = b % a ;
    m %= a ;
    (m *= powmod(bb,a-2,a)) %= a ;
    cost_b = m * z ;
    cost_a = (n - b * m) / a * y ;
    if(cost_a >= 0) chmin(res,cost_a+cost_b+cost_c) ;
    if(cost_a + cost_b + cost_c == 421032) cout << n - b * m << " " << m << " " << n << endl ;
    return res ;
}

void solve(){
    ll n , a , b , x , y , z ;
    cin >> n >> a >> b >> x >> y >> z ;
    ll g = gcd(a,b) ;
    // ll l = lcm(a,b) ;
    // ll cost_a = l / a * y ;
    // ll cost_b = l / b * z ;

    int count = 0 ;
    ll lef = 0 , rig = 1e9 ;
    while(count < 1000){
        ll ml = (2*lef+rig) / 3 * g , mr = (lef+2*rig) / 3 * g ;
        if(h(n,a,b,x,y,z,ml,g) > h(n,a,b,x,y,z,mr,g)) lef = ml ;
        else rig = mr ;
        count++ ;
    }
    ll res = x * n ;
    rrep(i,max(0LL,lef-1000LL),min(rig+1000LL,1000000000LL)) chmin(res,h(n,a,b,x,y,z,i,g)) ;
    cout << res << endl ;
}

int main(){
    // fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}