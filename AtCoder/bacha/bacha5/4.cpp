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
ld dp[101] ;

ld combination(int y , int x){
    ld p = 1 ;
    rep(i,x){
        p *= y - i ;
        p /= i + 1 ;
    }
    return p ;
}

ld powld(int y , int x){
    ld p = 1 ;
    rep(i,x) p *= y ;
    return p ;
}

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,2,n+1){
        ld e = 0 , sum = 0 ;
        rep(a,i+1) rep(b,i+1) {
            int c = i - a - b ;
            if(c < 0) continue ;
            if(a == i || b == i || c == i) e++ ;
            else if(a == b && b == c && c == a) e += combination(i,a) * combination(i-a,a) ;
            else if(a + b == i && a == b) sum += combination(i,a) * dp[a] ;
            else if(b + c == i && b == c) sum += combination(i,b) * dp[b] ;
            else if(c + a == i && c == a) sum += combination(i,c) * dp[c] ;
            else if(a == 0 && b < c) sum += combination(i,b) * dp[b] ;
            else if(a == 0 && b > c) sum += combination(i,c) * dp[c] ;
            else if(b == 0 && a < c) sum += combination(i,a) * dp[a] ;
            else if(b == 0 && a > c) sum += combination(i,c) * dp[c] ;
            else if(c == 0 && a < b) sum += combination(i,a) * dp[a] ;
            else if(c == 0 && a > b) sum += combination(i,b) * dp[b] ;
            else if(a < b && a < c) sum += combination(i,a) * combination(i-a,b) * dp[a] ;
            else if(b < a && b < c) sum += combination(i,b) * combination(i-b,a) * dp[b] ;
            else if(c < a && c < b) sum += combination(i,c) * combination(i-c,a) * dp[c] ;
            else if(a == b && a < c) sum += combination(i,a) * combination(i-a,b) * dp[a] ;
            else if(b == c && b < a) sum += combination(i,a) * combination(i-a,b) * dp[b] ;
            else if(c == a && c < b) sum += combination(i,a) * combination(i-a,b) * dp[c] ;
        }
        e /= powld(3,i) ;
        sum /= powld(3,i) ;
        dp[i] = (sum + 1) / (1 - e) ;
    }
    cout << fixed << setprecision(25) << dp[n] << endl ;
}