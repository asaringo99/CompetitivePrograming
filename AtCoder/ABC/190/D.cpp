#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e9

ll n ;

vector<ll> divisor(ll n){
    vector<ll> res ;
    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            res.push_back(i) ;
            if(i * i != n) res.push_back(n/i) ;
        }
    }
    return res ;
}

int main(){
    cin >> n ;
    vector<ll> res = divisor(2 * n) ;
    ll count = 0 ;
    for(int i = 0 ; i < res.size() ; i++){
        for(int j = i + 1 ; j < res.size() ; j++){
            if(res[i] * res[j] == 2 * n && abs(res[i] - res[j]) % 2 == 1) count++ ;
        }
    }
    cout << 2 * count << endl ;
}