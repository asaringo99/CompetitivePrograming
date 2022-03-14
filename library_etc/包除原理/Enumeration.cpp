#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , m ;
ll A[50] ;
double P[50] ;
ll ps[1 << 21] ; 
// ll us[2020200] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll  b){
    return (ll)min(2e18l+10 , a / gcd(a,b) * 1.0l * b) ;
}

void zeta(){
    rrep(i,1,1<<n){
        ll val = 1 ;
        rep(j,n) if(i >> j & 1) val = lcm(val,A[j]) ;
        ps[i] = m / val ;
    }
}

void mebius(){
    rep(i,n) rep(S,1<<n){
        if(S >> i & 1) ps[S] -= ps[S ^ (1 << i)] ;
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> P[i] ;
    zeta() ; mebius() ;
    double E = 0 ;
    rep(S,1<<n){
        double p = 1 ;
        rep(i,n){
            if(S >> i & 1) p *= (P[i] / 100) ;
            else p *= (100 - P[i]) / 100 ;
        }
        E += p * abs(ps[S]) ;
    }
    cout << fixed << setprecision(15) << E << endl ;
}