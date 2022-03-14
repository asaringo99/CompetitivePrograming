#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , X ;
int A[25] , B[25] ;

int main(){
    cin >> n >> X ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    for(int i = 0 ; i < n ; i++){
        if(X >> i & 1) B[i] = 1 ;
        else B[i] = 0 ;
    }
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(B[i]) sum += A[i] ;
    }
    cout << sum << endl ;
}