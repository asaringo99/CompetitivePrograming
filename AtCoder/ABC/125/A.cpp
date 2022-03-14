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

int a , b , c ;

int main(){
    cin.tie(0); // cin, coutの同期を切る
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c ;
    cout << c / a * b << endl ;
}