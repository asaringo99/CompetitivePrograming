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

int n , k ;
ll w[101010] ;

bool f(ll x){
    ll sum = 0 , cnt = 1 ;
    rep(i,n){
        if(w[i] > x) return false ;
        if(sum + w[i] > x) {
            sum = w[i] ;
            cnt++ ;
        }
        else sum += w[i] ;
    }
    return cnt <= k ;
}

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> w[i] ;
    ll lef = 0 , rig = 1e16 ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}