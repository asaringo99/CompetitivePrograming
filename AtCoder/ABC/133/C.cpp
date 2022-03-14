#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll l , r ;

int main(){
    cin >> l >> r ;
    ll res = 1e18 ;
    if(r - l <= 2019){
        rrep(i,l,r) rrep(j,i+1,r+1) res = min(res,(ll)i%2019*j%2019) ;
    }
    else{
        rrep(i,l,l+2020) rrep(j,i+1,l+2020) res = min(res,(ll)i%2019*j%2019) ;
    }
    cout << res << endl ;
}