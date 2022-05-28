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
int A[101010] , B[101010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int lef = 0 , rig = 0 ;
    set<int> st ;
    int res = 0 ;
    while(rig < n){
        while(rig < n && st.count(A[rig]) != 1){
            st.insert(A[rig]) ;
            rig++ ;
        }
        chmax(res,(int)st.size()) ;
        while(lef < n && A[lef] != A[rig]){
            st.erase(A[lef]) ;
            lef++ ;
        }
        st.erase(A[lef]) ;
        lef++ ;
        chmax(res,(int)st.size()) ;
    }
    chmax(res,(int)st.size()) ;
    cout << res << endl ;
}