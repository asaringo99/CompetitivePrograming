#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n ;

int main(){
    cin >> n ;
    ll A[n] , S[n+1] ;
    S[0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        S[i+1] = S[i] + A[i] ;
    }
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++) sum += A[i] * A[i] * (n - 1) ;
    for(int i = 0 ; i < n ; i++){
        sum -= 2 * A[i] * (S[n] - S[i + 1]) ;
    }
    cout << sum << endl ;
}