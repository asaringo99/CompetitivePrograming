#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[101010] , B[101010] ;

int main(){
    cin >> n ;
    rep(i,n+1) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    ll sum = 0 ;
    rep(i,n){
        if(B[i] > A[i]){
            sum += A[i] ;
            B[i] -= A[i] ;
            if(B[i] > A[i+1]){
                sum += A[i+1] ;
                A[i+1] = 0 ;
            }
            else{
                sum += B[i] ;
                A[i+1] -= B[i] ;
            }
        }
        else{
            sum += B[i] ;
        }
    }
    cout << sum << endl ;
}