#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    int res = 0 ;
    rep(i,n){
        int a ;
        cin >> a ;
        res ^= a ;
    }
    if(res != 0) cout << "Alice" << endl ;
    else cout << "Bob" << endl ;
}