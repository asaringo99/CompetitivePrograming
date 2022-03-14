#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll n ;

int main(){
    cin >> n ;
    int res = 0 ;
    for(ll i = 2 ; i * i <= 2 * n ; i++){
        if(n % i == 0) res++ ;
    }
    cout << res / 2 << endl ;
}