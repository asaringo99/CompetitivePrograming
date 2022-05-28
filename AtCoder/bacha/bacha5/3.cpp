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

int n ;
ld X[1010], Y[1010] , C[1010] ;

ld f(ld x){
    ld res = 0 ;
    rep(i,n) chmax(res,C[i] * abs(X[i] - x)) ;
    return res ;
}

ld g(ld x){
    ld res = 0 ;
    rep(i,n) chmax(res,C[i] * abs(Y[i] - x)) ;
    return res ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] >> C[i] ;
    ld lef = -1e6 , rig = 1e6 ;
    int count = 0 ;
    while(count < 200){
        ld lm = (lef * 2 + rig) / 3 , rm = (lef + rig * 2) / 3 ;
        if(f(lm) > f(rm)) lef = lm ;
        else rig = rm ;
        count++ ;
    }
    ld val_x = f(rig) ;
    
    count = 0 ;
    lef = -1e6 ;
    rig = 1e6 ;
    while(count < 200){
        ld lm = (lef * 2 + rig) / 3 , rm = (lef + rig * 2) / 3 ;
        if(g(lm) > g(rm)) lef = lm ;
        else rig = rm ;
        count++ ;
    }
    ld val_y = g(rig) ;

    cout << fixed << setprecision(25) << max(val_x,val_y) << endl ;
}