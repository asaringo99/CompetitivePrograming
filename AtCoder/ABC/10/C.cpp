#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "YES" << endl 
#define NO cout << "NO" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


ll sx , sy , gx , gy , T , V , n ;

int main(){
    cin >>sx >> sy >> gx >> gy >> T >> V >> n ;
    bool ok = false ;
    for(int i = 0 ; i < n ; i++){
        ll x , y ;
        cin >> x >> y ;
        double d1 = (x - sx) * (x - sx) + (y - sy) * (y - sy) ;
        double d2 = (x - gx) * (x - gx) + (y - gy) * (y - gy) ;
        d1 = sqrt(d1) ;
        d2 = sqrt(d2) ;
        if(d1 + d2 <= T * V) ok = true ;
    }
    if(ok) YES ;
    else NO ;
}