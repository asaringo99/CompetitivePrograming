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

const int mod = 1000000007 ;

int n ;
string S ;
string T[101] ;
ll dp[101010] ;

map<char,vector<string>> mp ;

int main(){
    fast_input_output
    cin >> n >> S ;
    int m = S.size() ;
    rep(i,4000) S += '0' ;
    rep(i,n) cin >> T[i] , mp[T[i][0]].push_back(T[i]) ;
    dp[0] = 1 ;
    rep(i,m){
        vector<string> vec = mp[S[i]] ;
        for(string t : vec){
            bool ok = true ;
            rep(k,t.size()) if(t[k] != S[i+k]) ok = false ;
            if(!ok) continue;
            (dp[i+t.size()] += dp[i]) %= mod ;
        }
    }
    cout << dp[m] << endl;
}