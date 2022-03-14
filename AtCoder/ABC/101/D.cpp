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

ll k ;

int main(){
    cin >> k ;
    if(k < 10){
        for(int i = 1 ; i <= k ; i++) cout << i << endl ;
        return 0 ;
    }
    for(int i = 1 ; i < 10 ; i++) cout << i << endl ;
    int i = 0 ;
    while(i + 10 <= k){
        cout << (i + 1) * 10 + 9 << endl ;
        i++ ;
    }
}