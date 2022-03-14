#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define endl "\n"
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , k ;
string S ;

int main(){
    cin.tie(0); // cin, coutの同期を切る
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> S ;
    map<char,char> rem ;
    rem['A'] = 'a' ;
    rem['B'] = 'b' ;
    rem['C'] = 'c' ;
    S[k-1] = rem[S[k-1]] ;
    cout << S << endl ;
}