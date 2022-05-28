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
int C[101010] ;

int main(){
    fast_input_output
    cin >> n ;
    int sum = 0 ;
    rep(i,n) cin >> C[i] , sum += C[i] ;
    if(sum == n || sum == 0){
        cout << -1 << endl ;
        return 0 ;
    }
    int res = 0 ;
    sum = 1 ;
    int bef = C[0] ;
    rrep(i,1,2*n){
        chmax(res,(sum-1)/2) ;
        if(C[i%n] == bef) sum++ ;
        else{
            bef = C[i%n] ;
            sum = 1 ;
        }
    }
    cout << res + 1 << endl ;
}