#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N (ll)1e6

ll n ;
map<ll,bool> used ;

int main(){
    cin >> n ;
    ll count = 0 ;
    ll N = n ;
    vector<ll> prime ;
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        while(n % i == 0){
        n /= i ;
        }
        prime.push_back(i) ;
    }
    if(n != 1) prime.push_back(n) ;
    vector<ll> is_prm ;
    for(int i = 0 ; i < prime.size() ; i++){
        ll k = prime[i] ;
        while(k <= N){
        is_prm.push_back(k) ;
        k *= prime[i] ;
        }
    }
    sort(is_prm.begin(),is_prm.end()) ;

    ll res = 0 ;
    for(int i = 0 ; i < is_prm.size() ; i++){
        if(N % is_prm[i] == 0){
        N /= is_prm[i] ;
        res++ ;
        }
    }
    cout << res << endl ;
}