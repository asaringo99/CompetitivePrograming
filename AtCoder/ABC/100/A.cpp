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

int main(){
    cin >> S ;
    int res = 0 ;
    for(int i = 0 ; i < 4 ; i++){
        if(S[i] == '+') res++ ;
        else res-- ;
    }
    cout << res << endl ;
}