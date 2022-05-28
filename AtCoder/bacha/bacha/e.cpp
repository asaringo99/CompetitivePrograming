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
int A[202020] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    if(k >= 500){
        rep(i,n) cout << n << " " ; cout << endl ;
        return 0 ;
    }
    rep(i,k){
        vector<int> vec(n+10,0) ;
        rep(i,n){
            int a = A[i] ;
            int l = i - a < 0 ? 0 : i - a ;
            int r = i + a + 1 >= n ? n : i + a + 1 ;
            vec[l]++ ; vec[r]-- ;
        }
        int sum = 0 ;
        rep(i,n){
            sum += vec[i] ;
            A[i] = sum ;
        }
    }
    rep(i,n) cout << A[i] << " " ; cout << endl ;
}