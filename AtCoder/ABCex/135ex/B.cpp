#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
int p[55] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] ;
    bool ok = true ;
    int count = 0 ;
    rep(i,n){
        if(p[i] != i + 1) count++ ;
    }
    if(count > 2) cout << "NO" << endl ;
    else cout << "YES" << endl ;
}