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
int T[101010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> T[i] ;
    ll a = 0 ;
    rep(i,n){
        bool ok = false ;
        rep(j,T[i]+1){
            if(j == T[i]){
                if(a >> j & 1){
                    if(!ok) a += 2LL * (ll)(1LL << j) ;
                }
                else{
                    a += (ll)(1LL << (ll)j) ;
                }
                break ;
            }
            if(a >> j & 1){
                a += (ll)(1LL << j) ;
                ok = true ;
            }
        }
    }
    cout << a << endl ;
}