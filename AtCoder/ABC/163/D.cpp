#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e6
#define mod (ll)(1e9+7)

ll n , k ;

int main(){
    cin >> n >> k ;
    ll A[n+1] ;
    A[0] = 0 ;
    for(int i = 1 ; i <= n ; i++) A[i] = A[i-1] + i ;
    ll ans = 0 ;
    for(int i = k ; i <= n ; i++){
        ans = (ans + (A[n] - A[n - i]) + mod - A[i - 1] + 1) % mod ;
    }
    cout << (ans + 1) % mod << endl ;
}