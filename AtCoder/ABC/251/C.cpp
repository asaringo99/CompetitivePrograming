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

int n ;
set<string> st ;
map<string,ll> mp ;

int main(){
    fast_input_output
    cin >> n ;
    int res = -1 , ans = 0 ;
    rep(i,n){
        string S ;
        ll T ;
        cin >> S >> T ;
        if(st.count(S) == 1) continue;
        st.insert(S) ;
        if(res < T){
            res = T ;
            ans = i + 1 ;
        }
    }
    cout << ans << endl ;
}