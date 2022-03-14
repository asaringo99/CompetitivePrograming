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
    for(int i = 1 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            for(int k = 0 ; k < 10 ; k++){
                if(i == j && j == k && 100 * i + 10 * j + k >= n){
                    cout << 100 * i + 10 * j + k << endl ;
                    return 0 ;
                }
            }
        }
    }
}