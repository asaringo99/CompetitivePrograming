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
    bool ok = true ;
    if(S[0] != 'A') ok = false ;
    bool o = false ;
    for(int i = 2 ; i < S.size() - 1 ; i++) if(S[i] == 'C') o = true ;
    ok = ok & o ;

    int count = 0 ;
    for(int i = 0 ; i < S.size() ; i++){
        for(char u : A_Z) if(u == S[i]) count++ ;
    }
    ok = ok & (count == 2) ;
    if(ok) cout << "AC" << endl ;
    else cout << "WA" << endl ;
}