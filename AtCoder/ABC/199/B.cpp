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

int n ;

int main(){
    cin >> n ;
    ll a = 0, b = LLONG_MAX ;
    for(int i = 0 ; i < n ; i++){
        ll A ;
        cin >> A ;
        a = max(a,A) ;
    }
    for(int i = 0 ; i < n ; i++){
        ll B ;
        cin >> B ;
        b = min(b,B) ;
    }
    ll res = b - a + 1 ;
    if(res <= 0) cout << 0 << endl ;
    else cout << res << endl ;
}