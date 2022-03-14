#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const double pi = 3.1415926536 ;

int n ;
double R[1010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> R[i] ;
    sort(R,R+n,greater<double>()) ;
    double res = 0 ;
    rep(i,n){
        if(i % 2 == 0) res += R[i] * R[i] * pi ;
        if(i % 2 != 0) res -= R[i] * R[i] * pi ;
    }
    cout << setprecision(15) << res << endl ;
}