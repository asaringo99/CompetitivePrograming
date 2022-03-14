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
    ll A[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        A[i] -= (i + 1) ;
    }
    sort(A,A+n) ;
    ll b1 = A[n/2] , b2 = A[(n-1)/2] ;
    ll sum1 = 0 , sum2 = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum1 += abs(A[i] - b1) ;
        sum2 += abs(A[i] - b2) ;
    }
    ll res = min(sum1,sum2) ;
    cout << res << endl ;
}