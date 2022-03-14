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

string S ;
ll k ;

int main(){
    cin >> S >> k ;
    int res = 1 ;
    for(int i = 0 ; i < k ; i++){
        if(S[i] != '1') {
            res = S[i] - '0' ;
            break ;
        }
    }
    cout << res << endl ;
}