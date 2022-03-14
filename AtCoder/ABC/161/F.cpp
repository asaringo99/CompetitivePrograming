#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , N ;
map<ll,ll> mp ;

int main(){
    cin >> n ;
    N = n ;
    ll k = n - 1 ;
    for(ll i = 2 ; i * i <= k ; i++){
        if(k % i != 0) continue ;
        while(k % i == 0){
            k /= i ;
            mp[i]++ ;
        }
    }
    if(k != 1) mp[k]++ ;

    ll res = 1 ;
    for(auto it : mp){
        res *= (it.second + 1) ;
    }

    set<ll> st ;
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i == 0){
            st.insert(i) ;
            st.insert(n/i) ;
        }
    }

    for(ll u : st){
        ll val = N ;
        while(val % u == 0) val /= u ;
        if(val % u == 1) res++ ;
    }

    cout << res << endl ;
}