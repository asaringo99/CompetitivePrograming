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
bool B[101] ;
vector<int> A[101] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) {
        int a ;
        cin >> a ;
        A[a].push_back(i) ;
    }
    rep(i,k) {
        int b ;
        cin >> b ;
        b-- ;
        B[b] = true ;
    }
    bool ok = false ;
    for(int i = 100 ; i > 0 ; i--){
        if(A[i].empty()) continue;
        for(int a : A[i]){
            if(B[a]) ok = true ;
        }
        break ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}