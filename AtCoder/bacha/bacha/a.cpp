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

string S ;
int n ;
int C[30] ;

int main(){
    fast_input_output
    cin >> S ;
    n = S.size() ;
    int eve = 0 ;
    rep(i,n) C[S[i]-'a']++ ;
    rep(i,26) if(C[i] % 2 == 1) eve++ ;
    if(eve == 0){
        cout << n << endl ;
        return 0 ;
    }
    n -= eve ;
    n /= 2 ;
    n /= eve ;
    n *= 2 ;
    n += 1 ;
    cout << n << endl ;
}