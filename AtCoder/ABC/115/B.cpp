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
    int sum = 0 ;
    int maxs = 0 ;
    for(int i = 0 ; i < n ; i++){
        int a ; 
        cin >> a ;
        sum += a ;
        maxs = max(maxs,a) ;
    }
    cout << sum - maxs / 2 << endl ;
}