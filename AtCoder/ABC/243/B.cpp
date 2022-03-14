#include <bits/stdc++.h>
using namespace std ;
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
ll A[1010] , B[1010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    int count = 0 ;
    rep(i,n) if(A[i] == B[i]) count++ ;
    cout << count << endl ;
    count = 0 ;
    rep(i,n) rep(j,n){
        if(A[i] == B[j] && i != j) count++ ;
    }
    cout << count << endl ;
}