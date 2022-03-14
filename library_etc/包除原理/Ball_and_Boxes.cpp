#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , k ;
ll comb[1010][1010] ;

ll powmod(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) (res *= x) %= mod ;
        (x *= x) %= mod ;
        n >>= 1 ;
    }
    return res ;
}

void pascal(){
    comb[0][0] = 1 ;
    rep(i,1010) rep(j,i + 1){
        (comb[i+1][j] += comb[i][j]) %= mod ;
        (comb[i+1][j+1] += comb[i][j]) %= mod ;
    }
}

int main(){
    pascal() ;
    cin >> n >> k ;
    ll res = powmod(k,n) , sum = 0 ;
    rrep(i,1,k+1){
        if(i % 2 == 1) sum += comb[k][i] * powmod(k-i,n) % mod ;
        if(i % 2 == 0) sum -= comb[k][i] * powmod(k-i,n) % mod ;
        (sum += mod) %= mod ;
    }
    cout << (res - sum + mod) % mod << endl ;
}