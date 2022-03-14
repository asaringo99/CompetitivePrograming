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
    int tmp = A[n-1] ;
    int res = 0 ;
    for(int i = 0 ; i < n - 1 ; i++){
        int k = min(tmp-A[i],A[i]) ;
        if(res < k){
            res = A[i] ;
        }
    }
    cout << tmp << " " << res << endl ;
}