#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n , a , b ;

int main(){
    cin >> n >> a >> b ;
    if(n * a < b) cout << n * a << endl ;
    else cout << b << endl ;
}