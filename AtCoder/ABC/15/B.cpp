#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    int count = 0 ;
    int sum = 0 ;
    rep(i,n) {
        int a ;
        cin >> a ;
        if(a == 0) continue ;
        count++ ;
        sum += a ;
    }
    int ans = sum / count ;
    if(sum % count != 0) ans++ ;
    cout << ans << endl ;
}