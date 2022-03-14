#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define dist(a,b,c,d) (a - b) * (a - b) + (c - d) * (c - d)

int n ;
double X[100] , Y[100] ;
double mx , my ;

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;

    double minval = 0 , maxval = 1e18 ;
    int count = 0 ;
    while(count < 500){
        double m = (minval + maxval) / 2 ;
        bool ok = true ;
        rep(i,n) rrep(j,i+1,n){
            if(4 * m * m < dist(X[i],X[j],Y[i],Y[j])) ok = false ;
        }
        if(ok) maxval = m ;
        else minval = m ;
        count++ ;
    }
    cout << setprecision(15) << maxval << endl ;
}