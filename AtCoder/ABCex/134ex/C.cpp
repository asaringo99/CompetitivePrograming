#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    int A[n] ;
    int maxval = 0 , secval = 0 , index = -1 ;
    rep(i,n){
        cin >> A[i] ;
        if(secval < A[i]) secval = A[i] ;
        if(maxval < secval){
            index = i ;
            swap(maxval,secval) ;
        }
    }
    rep(i,n){
        if(i == index) cout << secval << endl ;
        else cout << maxval << endl ;
    }
}