#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int L , R ;

int main(){
    cin >> L >> R ;
    if(R - L > 2500) {
        cout << 0 << endl ;
        return 0 ;
    }
    ll res = LLONG_MAX ;
    for(ll i = L ; i <= R ; i++){
        for(ll j = i + 1 ; j <= R ; j++) res = min(res,i % 2019 * j % 2019) ;
    }
    cout << res << endl ;
}