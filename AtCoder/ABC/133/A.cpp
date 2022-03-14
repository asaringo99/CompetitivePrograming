#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define long long int ;

int n , a , b ;

int main(){
    a = 10000000000 ;
    cout << a << endl ;
    cin >> n >> a >> b ;
    if(a * n < b) cout << a * n << endl ;
    else cout << b << endl ;
}