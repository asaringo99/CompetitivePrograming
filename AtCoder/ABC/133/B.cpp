#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , d ;

ll x[20][20];

int main(){
    cin >> n >> d ;
    rep(i,n) rep(j,d) cin >> x[i][j] ;
    ll res = 0  ;
    rep(i,n) rrep(j,i+1,n) {
        ll sum = 0 ;
        rep(k,d) sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]) ;
        if((ll)sqrt(sum) * (ll)sqrt(sum) == sum) res++ ;
    }
    cout << res << endl ;
}