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

ll n , k ;

int main(){
    cin >> n >> k ;
    ll one = n / k ;
    ll zer = 0 ;
    if(k % 2 == 0){
        ll half = k / 2 ;
        zer = n - half >= 0 ? (n - half) / k + 1 : 0 ;
    }
    cout << zer * zer * zer + one * one * one << endl ;
}