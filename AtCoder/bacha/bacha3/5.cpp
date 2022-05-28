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
ll C[101] ;
int S[101] ;
ld E[101] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> C[i] ;
    rep(i,n) rep(j,n) if(C[i] % C[j] == 0) S[i]++ ;
    rep(i,n) S[i]-- ;
    ld sum = 0 ;
    rep(i,n){
        rep(j,n){
            for(int k = 1 ; k < min(S[i],j) + 1 ; k += 2) {
                if(n - 1 - S[i] < j - k) continue;
                ld t = 1 ;
                for(ll x = 0 ; x < k ; x++){
                    t *= S[i] - x ;
                }
                for(ll x = 0 ; x < k ; x++){
                    t *= j - x ;
                    t /= x + 1 ;
                }
                for(ll x = 0 ; x < j - k ; x++){
                    t *= n - 1 - S[i] - x ;
                }
                for(ll x = 1 ; x <= n - j - 1 ; x++){
                    t *= x ;
                }
                sum += t ;
            }
        }
    }
    rep(i,n) sum /= i + 1 ;
    sum = n - sum ;
    cout << fixed << setprecision(25) << sum << endl ;
}