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

ll n ;
ll A[5] ;

int main(){
    cin >> n ;
    for(int i = 0 ; i < 5 ; i++) cin >> A[i] ;
    ll num = LLONG_MAX ;
    for(int i = 0 ; i < 5 ; i++) num = min(num,A[i]) ;
    ll res = 5 + (n - 1) / num ;
    cout << res << endl ;
}