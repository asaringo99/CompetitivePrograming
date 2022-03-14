#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int a , b ;

int main(){
    cin >> a >> b ;
    cout << (b - a % b) % b << endl ;
}