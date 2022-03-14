#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[101010] , res[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll sum = 0 ;
    rep(i,n){
        if(i % 2 == 0) sum += A[i] ;
        if(i % 2 == 1) sum -= A[i] ;
    }
    res[0] = sum ;
    rep(i,n-1){
        res[i+1] = 2 * A[i] - res[i] ;
    }
    rep(i,n) cout << res[i] << " " ;
    cout << endl ;
}