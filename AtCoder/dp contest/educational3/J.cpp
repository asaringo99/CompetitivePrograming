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
int A[303] , S[3] ;
ld dp[303][303][303] ;

ld rec(int i , int j , int k){
    if(i == 0 && j == 0 && k == 0) return dp[i][j][k] = 0 ;
    if(dp[i][j][k] != -1) return dp[i][j][k] ;
    ld sum = i + j + k ;
    ld e = (ld)n / sum ;
    ld res = e ;
    if(i != 0) res += i / sum * rec(i-1,j,k) ;
    if(j != 0) res += j / sum * rec(i+1,j-1,k) ;
    if(k != 0) res += k / sum * rec(i,j+1,k-1) ;
    return dp[i][j][k] = res ;
}

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) {
        cin >> A[i] ;
        S[A[i]-1]++ ;
    }
    rep(i,n+1) rep(j,n+1) rep(k,n+1) dp[i][j][k] = -1 ;
    cout << fixed << setprecision(25) << rec(S[0],S[1],S[2]) << endl ;
}