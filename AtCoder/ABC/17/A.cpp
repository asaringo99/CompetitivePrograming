#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int main(){
    int res = 0 ;
    for(int i = 0 ; i < 3 ; i++){
        int a , b ;
        cin >> a >> b ;
        res += a * b ;
    }
    cout << res / 10 << endl ;
}