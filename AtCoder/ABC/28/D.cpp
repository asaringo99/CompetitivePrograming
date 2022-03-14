#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

double n , k ;

int main(){
    cin >> n >> k ;
    ll lef = 0 , rig = 1e18 ;
    cout << fixed << setprecision(15) << (1 + (k - 1) * (n - k) * 6 + 3 * (n - 1)) / n / n / n << endl ;
}