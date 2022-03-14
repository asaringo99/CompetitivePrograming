#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

ll l , r ;
ll com[101][101] ;

void pascal(){
    com[0][0] = 1 ;
    rep(i,100) rep(j,100){
        (com[i+1][j] += com[i][j]) %= mod ;
        (com[i+1][j+1] += com[i][j]) %= mod ;
    }
}

vector<ll> f(ll x){
    vector<ll> vec(64,0) , X(64,0) ;
    int v = 0 ;
    while(x > 0){
        if(x & 1) X[v] = 1 ;
        else X[v] = 0 ;
        x >>= 1 ;
        v++ ;
    }
    int dig = 0 ;
    rep(i,64) if(X[i] == 1) dig = i ;
    int count = 0 ;
    for(int i = dig ; i >= 0 ; i--){
        if(X[i] != 0){
            vec[i]++ ;
            if(i == dig) rep(j,i) rep(k,64) (vec[count + k] += com[j][k]) %= mod ;
            if(i != dig) rep(j,i) rep(k,64) (vec[count + k + 1] += com[j][k]) %= mod ;
        }
        else{
            count++ ;
        }
    }
    return vec ;
}

int main(){
    pascal() ;
    cin >> l >> r ;
    vector<ll> vec1 = f(r) ;
    vector<ll> vec2 = f(l-1) ;
    rep(i,30) cout << vec1[i] << " " ;
    cout << endl ;
    rep(i,64) vec1[i] -= vec2[i] , (vec1[i] += mod) %= mod ;
    ll res = 0 ;
    rep(i,64) (res += vec1[i] * powmod(2,i)) %= mod ;
    cout << res << endl ;
}