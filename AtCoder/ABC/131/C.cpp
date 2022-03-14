#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return a / gcd(a,b) * b ;
}

ll a , b , c , d ;

int main(){
    cin >> a >> b >> c >> d ;
    a-- ;
    ll lef = a / c + a / d - a / lcm(c,d) ;
    ll rig = b / c + b / d - b / lcm(c,d) ;
    cout << b - a - (rig - lef) << endl ;
}