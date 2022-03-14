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

int n , t ;

int main(){
    cin >> n >> t ;
    int res = INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        int c , T ;
        cin >> c >> T ;
        if(T <= t) res = min(res,c) ;
    }
    if(res == INT_MAX) cout << "TLE" << endl ;
    else cout << res << endl ;
}