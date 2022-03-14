#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

ll X[200007] , Y[200007] ;

int main(){
    cin >> n ;
    rep(i,n){
        ll x , y ;
        cin >> x >> y ;
        X[i] = x + y ;
        Y[i] = x - y ;
    }
    sort(X,X+n) ;
    sort(Y,Y+n) ;
    cout << max(X[n-1] - X[0],Y[n-1] - Y[0]) << endl ;
}