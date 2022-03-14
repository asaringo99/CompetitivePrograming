#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
set<int> st ;
ll imos[100007] ;
ll tresure[100007] ;

int main(){
    cin >> n >> m ;
    ll sum = 0 ;
    rep(i,n){
        int l , r , s ;
        cin >> l >> r >> s ;
        sum += s ;
        imos[l] += s ;
        imos[r+1] -= s ;
        tresure[l] += 1 ;
        tresure[r+1] -= 1 ;
    }
    ll res = 0 ;
    ll S = 0 ;
    int num = 0 ;
    rrep(i,1,m+1){
        S += imos[i] ;
        res = max(res,sum-S) ;
    }
    cout << res << endl ;
}