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

char b ;

int main(){
    cin >> b ;
    map<char,char> rem ;
    rem['A'] = 'T' ;
    rem['T'] = 'A' ;
    rem['C'] = 'G' ;
    rem['G'] = 'C' ;
    cout << rem[b] << endl ;
}