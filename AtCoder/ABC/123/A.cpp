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

int k ;

int main(){
    int A[5] ;
    for(int i  = 0 ; i < 5 ; i++) cin >> A[i] ;
    cin >> k ;
    if(A[4] - A[0] <= k) cout << "Yay!" << endl ;
    else cout << ":(" << endl ;
}