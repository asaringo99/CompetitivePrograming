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
int A[1010101] ;
multiset<int> st ;

int main(){
    fast_input_output
    cin >> n >> L ;
    rep(i,n) cin >> A[i] ;
    int lef = 0 , rig = 0 ;
    rep(i,L) st.insert(A[i]) ;
    for(int i = 0 ; i + L <= n ; i++){
        auto it = st.begin() ;
        if(i+L<n) cout << *it << " " ;
        else cout << *it << endl ;
        st.erase(st.find(A[i])) ;
        if(i + L == n) break ;
        st.insert(A[i+L]) ;
    }
}