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
ld X[101010] , Y[101010] , S[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    ld res = 0 ;
    rep(i,n) res += X[i] * Y[(i+1)%n] - X[(i+1)%n] * Y[i] ;
    rep(i,2*n) S[i+1] = S[i] + 4 * (X[i%n] * Y[(i+1)%n] - X[(i+1)%n] * Y[i%n]) ;
    ld ans = LLONG_MAX ;
    int s = 0 ;
    int i = 1 ;
    while(i < 2 * n + 1){
        ll x = 4 * (X[i%n] * Y[s%n] - X[s%n] * Y[i%n]) ;
        if(i-s>1) chmin(ans,abs(res-(S[i]-S[s]+x))) ;
        while(s < i && S[i]-S[s]+x > res){
            if(i-s>1) chmin(ans,abs(res-(S[i]-S[s]+x))) ;
            s++ ;
            x = 4 * (X[i%n] * Y[s%n] - X[s%n] * Y[i%n]) ;
        }
        if(i-s>1) chmin(ans,abs(res-(S[i]-S[s]+x))) ;
        i++ ;
    }
    cout << (ll)(ans + 0.5) << endl ;
}