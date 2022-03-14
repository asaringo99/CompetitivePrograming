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

int n , q ;
string S ;

int main(){
    cin >> n >> q >> S ;
    int A[n+1] ;
    A[0] = A[1] = 0 ;
    for(int i = 2 ; i <= n ; i++){
        if(S[i-1] == 'C' && S[i-2] == 'A') A[i] = A[i-1] + 1 ;
        else A[i] = A[i-1] ;
    }
    for(int i = 0 ; i < q ; i++){
        int l , r ;
        cin >> l >> r ;
        cout << A[r] - A[l] << endl ;
    }
}