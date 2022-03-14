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

int n , m ;

int main(){
    cin >> n >> m ;
    ll S[n+1] ;
    S[0] = 0 ;
    map<int,int> rem ;
    rem[0] = 1 ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        ll a ;
        cin >> a ;
        S[i+1] = S[i] + a ;
        res += rem[S[i+1] % m] ;
        rem[S[i+1] % m]++ ;
    }
    cout << res << endl ;
}