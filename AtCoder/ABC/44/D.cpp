#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n , s ;

int main(){
    cin >> n >> s ;
    if(s > n){
        cout << -1 << endl ;
        return 0 ;
    }
    if(s == n){
        cout << s + 1 << endl ;
        return 0 ;
    }
    rrep(b,2,1000001){
        ll k = n , sum = 0 ;
        while(k > 0){
            sum += k % b ;
            k /= b ;
        }
        if(sum == s){
            cout << b << endl ;
            return 0 ;
        }
    }
    ll res = -1 ;
    for(ll i = 1 ; i * i <= n - s ; i++){
        if((n - s) % i == 0){
            ll x = i ;
            ll b = (n - s) / i + 1 ;
            if(x >= b) continue ;
            if(s - x >= b) continue ;
            if(s - x < 0) continue ;
            if(b <= 1000000) continue ;
            res = b ;
        }
    }
    cout << res << endl ;
}