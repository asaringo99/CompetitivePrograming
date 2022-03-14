#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll lim ;

int main(){
    cin >> lim ;
    for(int i = 0 ; i <= 15 ; i++){
        ll digit = pow(10,i) ;
        for(int j = 1 ; j <= 9 ; j++){
            if(lim == 0) return 0 ;
            ll tmp = digit * j ;
            ll pes = 0 ;
            for(int k = 0 ; k < i ; k++){
                pes += pow(10,k) * 9 ;
            }
            cout << pes + tmp << endl ;
            lim-- ;
        }
    }
}