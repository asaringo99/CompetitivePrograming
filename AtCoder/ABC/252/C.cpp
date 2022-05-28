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
string S[101] ;
multiset<int> T[10] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> S[i] ;
    rep(i,n){
        for(int j = 0 ; j < 10 ; j++){
            T[S[i][j]-'0'].insert(j) ;
        }
    }
    int res = 1e9 ;
    rep(i,10){
        int t = -1 , count = 0 ;
        rep(j,n){
            auto it = T[i].upper_bound(t) ;
            if(it == T[i].end()){
                count++ ;
                it = T[i].lower_bound(0) ;
                t = *it ;
                T[i].erase(it) ;
            }
            else{
                t = *it ;
                T[i].erase(it) ;
            }
        }
        chmin(res, count * 10 + t) ;
    }
    cout << res << endl ;
}