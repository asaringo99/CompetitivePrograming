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

int n , m ;
vector<P> vec ;

int main(){
    fast_input_output
    cin >> n >> m ;
    if(n == 1 && m == 0){
        cout << 1 << " " << 2 << endl ;
        return 0 ;
    }
    if(m >= n - 1 || m < 0){
        cout << -1 << endl ;
        return 0 ;
    }
    ll s = 10000000 , t = 10000000 - 1 ;
    rep(i,m+1){
        vec.push_back(P(s,s+1)) ;
        s += 2 ;
    }
    rep(i,n-m-1){
        vec.push_back(P(t,s)) ;
        t-- ;
        s++ ;
    }
    for(P p : vec) cout << p.first << " " << p.second << endl ;
}