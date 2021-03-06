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
int A[101010] , C[101010] ;
set<int> st ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    int lef = 0 , rig = 0 , res = 1e8 ;
    while(rig < n){
        while(rig < n && st.size() < k){
            if(A[rig] <= k) st.insert(A[rig]) ;
            C[A[rig]]++ ;
            rig++ ;
        }
        if(st.size() < k) break ;
        while(lef < n && st.size() == k){
            res = min(res,rig-lef) ;
            C[A[lef]]-- ;
            if(C[A[lef]] == 0) st.erase(A[lef]) ;
            lef++ ;
        }
    }
    if(res == 1e8) res = 0 ;
    cout << res << endl ;
}