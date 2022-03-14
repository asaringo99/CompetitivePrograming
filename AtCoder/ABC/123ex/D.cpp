#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int x , y , z , k ;
ll A[1010] , B[1010] , C[1010] ;
ll X[1010101] , Y[3030303] ;

int main(){
    cin >> x >> y >> z >> k ;
    rep(i,x) cin >> A[i] ;
    rep(i,y) cin >> B[i] ;
    rep(i,z) cin >> C[i] ;
    rep(i,x) rep(j,y) X[i*x+j] = A[i] + B[j] ;
    sort(X,X+x*y,greater<ll>()) ;
    rep(i,min(k,x*y)) rep(j,z) Y[i*z+j] = X[i] + C[j] ;
    sort(Y,Y+min(k,x*y)*z,greater<ll>()) ;
    rep(i,k) cout << Y[i] << endl ;
}