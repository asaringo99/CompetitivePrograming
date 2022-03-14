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

int r ;

int main(){
    cin >> r ;
    if(r < 1200) cout << "ABC" << endl ;
    else if(r < 2800) cout << "ARC" << endl ;
    else cout << "AGC" << endl ;
}