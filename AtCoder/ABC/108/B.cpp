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

int x1 , yl , x2 , y2 ;

int main(){
    cin >> x1 >> yl >> x2 >> y2 ;
    int dx = x2 - x1 , dy = y2 - yl ;
    cout << x2 - dy << " " << y2 + dx << " " << x1 - dy << " " << yl + dx << endl ;
}