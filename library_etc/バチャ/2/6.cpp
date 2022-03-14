#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n ;
string S ;
int A[202020][26] ;

int main(){
    cin >> S ;
    n = S.size() ;
    rep(i,n){
        rep(j,26) A[i+1][j] = A[i][j] ;
        A[i+1][S[i]-'a']++ ;
    }
    ll res = n * (n - 1) / 2 + 1 ;
    rep(i,n) res -= A[n][S[i]-'a'] - A[i+1][S[i]-'a'] ;
    cout << res << endl ;
}