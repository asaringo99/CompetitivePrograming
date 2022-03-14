#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , d ;

int main(){
    cin >> n >> d ;
    if(n % (2 * d + 1) == 0) cout << n / (2 * d + 1) << endl ;
    else cout << n / (2 * d + 1) + 1 << endl ;
}