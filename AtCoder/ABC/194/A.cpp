#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int a , b ;

int main(){
    cin >> a >> b ;
    int c = a + b ;
    if(c >= 15 && b >= 8) cout << 1 << endl ;
    else if(c >= 10 && b >= 3) cout << 2 << endl ;
    else if(c >= 3) cout << 3 << endl ;
    else cout << 4 << endl ;
}