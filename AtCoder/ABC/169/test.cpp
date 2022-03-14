#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N (ll)1e6

int main(){
    ll n ;
    cin >> n ;
    set<ll> rem ;
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        ll p = i , t = n / i , q = n ;
        while(q % p == 0){
            q /= p ;
            rem.insert(p) ;
            p *= i ;
        }
        q = n ;
        while(q % t == 0){
            q /= t ;
            rem.insert(t) ;
            t *= (n/i) ;
        }
    }
    if(n != 1) rem.insert(n) ;
    int count = 0 ;
    for(auto it = rem.begin() ; it != rem.end() ; it++){
        if(n % *it == 0){
            count++ ;
            n /= *it ;
        }
    }
    cout << count << endl ;
}