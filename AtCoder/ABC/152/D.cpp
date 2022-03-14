#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

map<int,ll> sta , fin ;

int main(){
    cin >> n ;
    ll res = 0 ;
    for(int a = 1 ; a <= n ; a++){
        string s = to_string(a) ;
        int b = 0 ;
        for(int j = 0 ; j < s.size() ; j++) b += pow(10,j) * (s[j] - '0') ;
        cout << a << " " << b << endl ;
        if(a % 10 != 0 && b <= n) res++ ;
    }
    cout << res << endl ;
}