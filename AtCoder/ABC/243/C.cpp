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

int n ;
int X[202020] , Y[202020] ;
string S ;
map<int,bool> yl , yr ;
map<int,int> l , r ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    rep(i,n) r[Y[i]] = INT_MAX ;
    cin >> S ;
    rep(i,n){
        if(S[i] == 'L') {
            yl[Y[i]] = true ;
            chmax(l[Y[i]],X[i]) ;
        }
        if(S[i] == 'R') {
            yr[Y[i]] = true ;
            chmin(r[Y[i]],X[i]) ;
        }
    }
    bool ok = false ;
    rep(i,n){
        if(yl[Y[i]] && yr[Y[i]] && r[Y[i]] < l[Y[i]]) ok = true ;
    }
    if(ok) cout  << "Yes" << endl ;
    else cout  << "No" << endl ;
}