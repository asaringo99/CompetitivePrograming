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
    map<char,char> big , sma ;
    for(int i = 0 ; i < 26 ; i++){
        sma[a_z[i]] = a_z[i] ;
        sma[A_Z[i]] = a_z[i] ;
        big[a_z[i]] = A_Z[i] ;
        big[A_Z[i]] = A_Z[i] ;
    }
    cout << big[S[0]] ;
    for(int i = 1 ; i < n ; i++){
        cout << sma[S[i]] ;
    }
    cout << endl ;
}