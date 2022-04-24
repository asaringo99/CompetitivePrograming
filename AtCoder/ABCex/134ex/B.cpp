#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , d ;

int main(){
    cin >> n >> d ;
    d = 2 * d + 1 ;
    int res = n % d == 0 ? n / d : n / d + 1 ;
    cout << res << endl ;
}