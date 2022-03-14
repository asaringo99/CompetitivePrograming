#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int a , b ;

int main(){
    cin >> a >> b ;
    if(1 <= a && a <= 9 && 1 <= b && b <= 9) cout << a * b << endl ;
    else cout << -1 << endl ;
}