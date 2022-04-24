#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int a , b ;

int main(){
    cin >> a >> b ;
    if(a > b) swap(a,b) ;
    if((b - a) % 2 == 1) cout << "IMPOSSIBLE" << endl ;
    else cout << (b + a) / 2 << endl ;
}