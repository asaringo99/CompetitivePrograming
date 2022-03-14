#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
double v[1010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> v[i] ;
    sort(v,v+n) ;
    rep(i,n-1) v[i+1] = (v[i] + v[i + 1]) / 2 ;
    cout << fixed << setprecision(15) << v[n-1] << endl ;
}