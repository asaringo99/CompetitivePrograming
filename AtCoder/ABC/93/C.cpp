#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        ll val = a * b ;
        ll root = sqrt(val) ;
        ll tmp = val / root ;
        ll sum = 0 ;
        if(tmp == root) sum = 2 * root - 2 ;
        else sum = 2 * root - 1 ;
        if(root * root == val) sum-- ;
        if(a == b) sum++ ;
        if(abs(a-b) == 1) sum-- ;
        cout << sum << endl ;
    }
}