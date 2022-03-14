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

ll r , x , y ;

int main(){
    cin >> r >> x >> y ;
    ll R = x * x + y * y ;
    ll dir = r ;
    if(R < r * r){
        cout << 2 << endl ;
        return 0 ;
    }
    int i = 1 ;
    while(true){
        ll tmp = dir * dir ;
        if(tmp >= R){
            cout << i << endl ;
            return 0 ;
        }
        dir += r ;
        i++ ;
    }
}