#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;

int main(){
    cin >> n ;
    double sum = 0 ;
    rep(i,n){
        double a ;
        cin >> a ;
        sum += 1 / a ;
    }
    sum = 1 / sum ;
    cout << fixed << setprecision(15) << sum << endl ;
}