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

int n , k ;

int main(){
    cin >> n >> k ;
    ll res = 0 ;
    for(int i = k ; i < n ; i++){
        for(int j = 1 ; j * j <= n - i ; j++){
            if(i % j == 0){
                if(j > i) res++ ;
            }
        }
    }
}