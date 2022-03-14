#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll x , y ;

int main(){
    cin >> x >> y ;
    if(abs(x - y) < 2) cout << "Brown" << endl ;
    else cout << "Alice" << endl ;
}