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

int n ;

int main(){
    cin >> n ;
    int h = n / 3600 , m = (n % 3600) / 60 , s = (n % 3600) % 60 ;
    if(h < 10) cout << "0" << h << ":" ;
    else cout << h << ":" ;
    if(m < 10) cout << "0" << m << ":" ;
    else cout << m << ":" ;
    if(s < 10) cout << "0" << s << endl ;
    else cout << s << endl ;
}