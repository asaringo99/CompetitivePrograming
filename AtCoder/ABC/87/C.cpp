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

int main(){
    cin >> n ;
    int A1[n+1] , A2[n+1] ;
    A1[0] = 0 ;
    A2[0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        A1[i+1] = a + A1[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        A2[i+1] = a + A2[i] ;
    }
    int res = 0 ;
    for(int i = 1 ; i <= n ; i++){
        res = max(res,A1[i]+A2[n]-A2[i-1]) ;
    }
    cout << res << endl ;
}