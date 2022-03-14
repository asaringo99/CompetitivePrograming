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

string S , T ;

int main(){
    cin >> S >> T ;
    bool ok = false ;
    for(int i = 0 ; i < S.size() ; i++){
        string tmp = "" ;
        for(int j = 0 ; j < S.size() ; j++){
            tmp += S[(i + j) % S.size()] ;
        }
        if(tmp == T) ok = true ;
    }
    if(ok) YES ;
    else NO ;
}