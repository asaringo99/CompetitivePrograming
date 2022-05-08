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
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int t ;

void solve(){
    string l , r ;
    cin >> l >> r ;
    ll lef = 0 , rig = 0 ;
    for(char u : l) lef *= 10 , lef += (u - '0') ;
    for(char u : r) rig *= 10 , rig += (u - '0') ;
    if(l.size() == r.size()){
        cout << rig - lef + 1 << endl ;
        return ;
    }
    if(r[0] != '1'){
        cout << rig - powll(10,r.size()-1) + 1 << endl ;
        return ;
    }
    if(r[1] == '0'){
        if(rig / 10 < lef) cout << rig - lef + 1 << endl ;
        else cout << rig - rig / 10 << endl ;
        return ;
    }
    ll dig = powll(10,r.size()-1) ;
    ll vvv = max(rig-dig,rig/10) ;
    if(vvv < lef) cout << rig - lef + 1 << endl ;
    else cout << rig - vvv << endl ;
    return ;
}

int main(){
    // fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}