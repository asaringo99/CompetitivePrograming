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
    int k = S.size() - 1 ;
    while(S[k] == '0') k-- ;
    int n = (k + 1) / 2 ;
    bool ok = true ;
    for(int i = 0 ; i < n ; i++){
        if(S[i] != S[k - i]) ok = false ;
    }
    if(ok) YES ;
    else NO ;
}