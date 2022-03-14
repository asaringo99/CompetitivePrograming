#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
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

int n ;
ll x ;
string S ;

int main(){
    cin >> n >> x >> S ;
    x-- ;
    int count = 0 ;
    rep(i,n){
        if(count > 0){
            if(S[i] == 'L') count++ ;
            if(S[i] == 'R') count++ ;
            if(S[i] == 'U') count-- ;
        }
        else{
            if(S[i] == 'L'){
                if(x * 2 + 1 > 1000000000000000000LL) count++ ;
                else x = 2 * x + 1 ;
            }
            if(S[i] == 'R'){
                if(x * 2 + 2 > 1000000000000000000LL) count++ ;
                else x = 2 * x + 2 ;
            }
            if(S[i] == 'U') x = (x - 1) / 2 ;
        }
    }
    cout << x + 1 << endl ;
}