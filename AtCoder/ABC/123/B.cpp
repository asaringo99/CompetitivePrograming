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

int A[5] ;

int main(){
    for(int i = 0 ; i < 5 ; i++) cin >> A[i] ;
    int res = INT_MAX ;
    for(int i = 0 ; i < 5 ; i++){
        int val = 0 ;
        for(int j = 0 ; j < 5 ; j++){
            if(i == j) val += A[j] ;
            else{
                val += A[j] % 10 == 0 ? A[j] : (A[j] / 10 + 1) * 10 ;
            }
        }
        res = min(res,val) ;
    }
    cout << res << endl ;
}