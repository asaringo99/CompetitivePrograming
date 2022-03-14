#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll k ;

int main(){
    cin >> k ;
    ll val = k / 50 + 50 ;
    ll mod = k % 50 ;
    cout << 50 << endl ;
    rep(i,51){
        if(i == mod) {
            val-- ;
            continue ;
        }
        if(val <= 0) cout << 0 << endl ;
        else cout << val << " " ;
        val-- ;
    }
    cout << "\n" ;
}