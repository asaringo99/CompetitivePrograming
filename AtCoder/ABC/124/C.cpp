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
    int n = S.size() ;
    int res = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(S[i] == S[i-1]){
            res++ ;
            if(S[i-1] == '0') S[i] = '1' ;
            if(S[i-1] == '1') S[i] = '0' ;
        }
    }
    cout << res << endl ;
}