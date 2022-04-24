#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const ld pi = 3.1415926535 ;

ld a , b , x ;

int main(){
    cin >> a >> b >> x ;
    x /= a ;
    if(b * a < 2 * x){
        ld v = 2 * x / a ;
        v -= b ;
        v = b - v ;
        ld theta = atan2l(a,v) ;
        cout << fixed << setprecision(20) << (pi / 2 - theta) * 180 / pi << endl ;
    }
    else{
        ld v = 2 * x / b ;
        ld theta = atan2l(b,v) ;
        cout << fixed << setprecision(20) << theta * 180 / pi << endl ;
    }
}