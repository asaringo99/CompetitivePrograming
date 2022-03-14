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
ll a , b , c , d , e , h ;

int main(){
    cin >> n >> h ;
    cin >> a >> b >> c >> d >> e ;
    ll res = LLONG_MAX ;
    for(int z = 0 ; z <= n ; z++){
        ll x , y ;
        ll val = (d + e) * z - d * n - h ;
        if(val < 0) x = 0 ;
        else{
            x = val / (b - d) + 1 ;
        }
        y = n - x - z ;
        if(y < 0) continue ;
        res = min(a * x + c * y , res) ;
    }
    cout << res << endl ;
}