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

int n , k , a ;

int main(){
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++) cin >> a ;
    k-- ;
    int res = (n - 1) / k ;
    if((n-1) % k != 0) res++ ;
    cout << res << endl ;
}