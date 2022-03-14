#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int a , b , c ;

int main(){
    cin >> a >> b >> c ;
    cout << max({a+b,a-b,a*b}) << endl;
}