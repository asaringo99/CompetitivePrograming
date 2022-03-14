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

int n ;

int main(){
    cin >> n ;
    int res = 0 ;
    for(int i = 1 ; i <= n ; i+=2){
        int count = 0 ;
        for(int j = 1 ; j * j < i ; j++){
            if(i % j == 0) count += 2 ;
            if(j * j == i) count-- ;
        }
        if(count == 8) res++ ;
    }
    cout << res << endl ;
}