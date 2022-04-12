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

int n , k ;
vector<P> res ;

int main(){
    fast_input_output
    cin >> n >> k ;
    if((n - 2) * (n - 1) / 2 < k){
        cout << -1 << endl ;
        return 0 ;
    }
    rrep(j,2,n+1){
        res.push_back(P(1,j)) ;
    }
    int m = (n - 2) * (n - 1) / 2 ;
    rrep(i,2,n+1){
        rrep(j,i+1,n+1){
            if(m == k) break ;
            res.push_back(P(i,j)) ;
            m-- ;
        }
    }
    cout << res.size() << endl;
    rep(i,res.size()) cout << res[i].first << " " << res[i].second << endl ;
}