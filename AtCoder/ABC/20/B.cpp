#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int a , b ;

int main(){
    cin >> a >> b ;
    string S = to_string(b) ;
    int n = S.size() ;
    cout << ((ll)pow(10,n) * a + b) * 2 << endl ;
}