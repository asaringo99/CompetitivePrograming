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

int main(){
    int A[3] ;
    cin >> A[0] >> A[1] >> A[2] ;
    sort(A,A+3) ;
    cout << A[2] - A[0] << endl ;
}