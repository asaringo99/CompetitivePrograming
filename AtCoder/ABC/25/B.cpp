#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , a , b ;

int main(){
    cin >> n >> a >> b ;
    int x = 0 ;
    rep(i,n){
        string s ; int d ;
        cin >> s >> d ;
        if(d < a) d = a ;
        else if(d > b) d = b ;
        if(s == "East") x += d ;
        else x -= d ;
    }
    if(x > 0) cout << "East" << " " << abs(x) << endl ;
    if(x < 0) cout << "West" << " " << abs(x) << endl ;
    if(x == 0) cout << 0 << endl ;
}