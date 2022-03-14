#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , v , a , b , c ;

int main(){
    cin >> v >> a >> b >> c ;
    while(true){
        v -= a ;
        if(v < 0){
            cout << 'F' << endl ;
            return 0 ;
        }
        v -= b ;
        if(v < 0){
            cout << 'M' << endl ;
            return 0 ;
        }
        v -= c ;
        if(v < 0){
            cout << 'T' << endl ;
            return 0 ;
        }
    }
}