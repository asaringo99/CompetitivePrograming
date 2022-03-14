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
    int H[n] ;
    for(int i = 0 ; i < n ; i++) cin >> H[i] ;
    sort(H,H+n) ;
    int magin = INT_MAX ;
    for(int i = 0 ; i < n - k + 1 ; i++){
        magin = min(magin,H[i+k-1] - H[i]) ;
    }
    cout << magin << endl ;
}