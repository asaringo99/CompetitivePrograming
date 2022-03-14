#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
int n ;

int main(){
    cin >> S >> n ;
    rep(i,n){
        int l , r ;
        cin >> l >> r ;
        l-- ;
        r-- ;
        rep(j,(r-l+1)/2) swap(S[l+j],S[r-j]) ;
    }
    cout << S << endl ;
}