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

ll n ;

int main(){
    cin >> n ;
    ll res = 1e18 ;
    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            ll a = n / i ;
            chmin(res,a+i-2) ;
        }
    }
    cout << res << endl ;
}