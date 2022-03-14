#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int a , b , w ;

int main(){
    cin >> a >> b >> w ;
    w *= 1000 ;
    int less , bett ;
    if(w % b == 0) less = w / b ;
    else less = w / b + 1 ;
    bett = w / a ;
    if(b * bett < w){
        cout << "UNSATISFIABLE" << endl ;
        return 0 ;
    }
    else{
        cout << less << " " << bett << endl ;
    }
}