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
    int A[n] ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    sort(A,A+n) ;
    int k = n / 2 ;
    for(int i = 0 ; i < n ; i++){
        if(i == k) cout << A[k + 1] << endl ;
        else cout << A[k] << endl ;
    }
}