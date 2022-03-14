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

ll n , k ;
ll digit[45] ;

ll powcal(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int main(){
    cin >> n >> k ;
    memset(digit,0,sizeof(digit)) ;
    ll A[n] ;
    for(int i = 0 ; i < n ; i++){
        ll a ;
        cin >> a ;
        A[i] = a ;
        for(int j = 0 ; j < 45 ; j++){
            if(a >> j & 1) digit[j]++ ;
        }
    }
    ll x = 0 ;
    for(int i = 44 ; i >= 0 ; i--){
        ll tmp = powcal(2,i) ;
        if(2 * digit[i] >= n || x + tmp > k) continue ;
        x += tmp ;
    }
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++) res += (x ^ A[i]) ;
    cout << res << endl ;
}