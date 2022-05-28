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
string S , T ;
int A[30] , B[30] ;

int main(){
    fast_input_output
    cin >> S >> T ;
    for(char u : S) A[u-'a']++ ;
    for(char u : T) B[u-'a']++ ;
    for(int i = 0 ; i < 26 ; i++) if(A[i] != B[i]){
        cout << "NO" << endl ;
        return 0 ;
    }
    bool ss = false ;
    rep(i,26) if(A[i] > 1) ss = true ;

    n = S.size() ;
    int count = 3 ;
    rep(i,n){
        if(S[i] == T[i]) continue ;
        rrep(j,i+1,n){
            if(S[j] == T[i] && S[i] == T[j]){
                swap(S[i],S[j]) ;
                count-- ;
                break ;
            }
        }
    }
    if(count < 0 || (count == 1 && !ss)){
        cout << "NO" << endl;
        return 0 ;
    }
    rep(i,n){
        if(S[i] != T[i]) count-- ;
    }
    count++ ;
    if(count == 4 && !ss) cout << "NO" << endl ;
    else if(count >= 0) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}