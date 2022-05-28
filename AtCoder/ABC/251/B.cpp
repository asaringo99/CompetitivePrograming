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
ll w ;
ll A[303] ;
set<int> st ;

int main(){
    fast_input_output
    cin >> n >> w ;
    rep(i,n) cin >> A[i] ;
    int res = 0 ;
    rep(i,n) rrep(j,i+1,n) rrep(k,j+1,n) {
        if(A[i] + A[j] + A[k] <= w) st.insert(A[i] + A[j] + A[k]) ;
    }
    rep(i,n) rrep(j,i+1,n) {
        if(A[i] + A[j] <= w) st.insert(A[i] + A[j]) ;
    }
    rep(i,n) {
        if(A[i] <= w) st.insert(A[i]) ;
    }
    cout << st.size() << endl ;
}