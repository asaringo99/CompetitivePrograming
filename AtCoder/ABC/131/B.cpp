#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n , L ;

int main(){
    fast_input_output
    cin >> n >> L ;
    int res = 1e8 ;
    int sum = 0 ;
    int ans = -1 ;
    rep(i,n) sum += L + i ;
    rep(i,n) {
        if(res > abs(sum - (sum-(L+i)))) {
            res = abs(sum - (sum-(L+i))) ;
            ans = sum - (L+i) ;
        }
    }
    cout << ans << endl ;
}