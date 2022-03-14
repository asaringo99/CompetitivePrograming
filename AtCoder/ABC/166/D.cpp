#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll x ;

int main(){
    cin >> x ;
    for(ll i = -3000 ; i <= 3000 ; i++){
        for(ll j = -3000 ; j <= 3000 ; j++){
            if(i * i * i * i * i - j * j * j * j * j == x){
                cout << i << " " << j << endl ;
                return 0 ;
            }
        }
    }
}