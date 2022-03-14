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
    int A[n] , num ;
    for(int i = 0 ; i < n ; i++) {
        cin >> A[i] ;
        if(A[i] == 1) num = i ;
    }
    int cnt1 = num / (k - 1) + 1 ;
    cout << num << " " << k - 1 << endl ;
    if(num % (k - 1) == 0) cnt1-- ;
    int cnt2 = (n - 1 - num) / (k - 1) + 1 ;
    if((n - 1 - num) % (k - 1) == 0) cnt2-- ;
    cout << cnt1 << " " << cnt2 << endl ;
}