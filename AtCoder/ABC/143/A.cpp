#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int a , b ;

int main(){
    cin >> a >> b ;
    if(a < 2 * b) cout << 0 << endl ;
    else cout << a - 2 * b << endl ;
}