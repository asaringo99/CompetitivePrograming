#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
ll A[100007] , B[100007] ;

int main(){
    cin >> n ;
    rep(i,n+1) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    ll res = 0 ;
    rep(i,n){
        ll tmp = B[i] - A[i] ;
        if(tmp <= 0){
            res += B[i] ;
            continue ;
        }
        res += A[i] ;
        B[i] -= A[i] ;
        ll smp = B[i] - A[i+1] ;
        if(smp <= 0){
            res += B[i] ;
            A[i+1] -= B[i] ;
            continue ;
        }
        res += A[i+1] ;
        A[i+1] = 0 ;
    }
    cout << res << endl ;
}