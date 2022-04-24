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

int x , y , z , k ;
ll A[1010] , B[1010] , C[1010] ;
vector<ll> D , E ;

int main(){
    fast_input_output
    cin >> x >> y >> z >> k ;
    rep(i,x) cin >> A[i] ;
    rep(i,y) cin >> B[i] ;
    rep(i,z) cin >> C[i] ;
    rep(i,x) rep(j,y) D.push_back(A[i]+B[j]) ;
    sort(D.begin(),D.end(),greater<ll>()) ;
    int m = min(k,(int)D.size()) ;
    rep(i,m) rep(j,z) E.push_back(D[i]+C[j]) ;
    sort(E.begin(),E.end(),greater<ll>()) ;
    ll res = 0 ;
    rep(i,k) cout << E[i] << endl ;
}