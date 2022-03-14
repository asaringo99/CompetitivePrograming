#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int a , b ;

int main(){
    cin >> a >> b ;
    if(a < b) swap(a,b) ;
    if(a % b == 0){
        cout << "stan wins" << endl ;
        return 0 ;
    }
    bool stan = true ;
    while(a / b == 1){
        stan ^= 1 ;
        a %= b ;
        swap(a,b) ;
    }
    if(stan) cout << "Stan wins" << endl ;
    else cout << "Ollie wins" << endl ;
}