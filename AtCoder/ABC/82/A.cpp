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
    if((a + b) % 2 == 0) cout << (a + b) / 2 << endl ;
    else cout << (a + b) /2 + 1 << endl ; 
}