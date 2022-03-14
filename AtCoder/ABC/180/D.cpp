#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define MAX_N (ll)2e5

ll x , y , a , b ;

int main(){
    cin >> x >> y >> a >> b ;
    ll experience = 0 ;
    if(x < (ll)1e9)
    while(x * a <= x + b){
        if(x * a >= y){
            cout << experience << endl ;
            return 0 ;
        }
        x *= a ;
        experience++ ;
    }
    y -= x ;
    experience += (y - 1) / b ;
    cout << experience << endl ;
}