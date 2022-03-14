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

int n , k ;

int main(){
    cin >> n >> k ;
    ll X[n+1] ;
    X[0] = 0 ;
    for(int i = 1 ; i < n + 1 ; i++) cin >> X[i] ;
    sort(X,X+n+1) ;
    int lef = 0 , rig = k ;
    ll sum = 0 , res = LLONG_MAX ;
    while(rig < n + 1){
        if(X[rig] < 0 || X[lef] > 0) {
            lef++ ;
            rig++ ;
            continue ;
        }
        res = min(res,abs(X[lef]) + abs(X[rig]) + min(abs(X[lef]),abs(X[rig]))) ;
        lef++ ;
        rig++ ;
    }
    cout << res << endl ;
}