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

int n , m ;
int s , t ;
vector<int> G[303030] ;
vector<int> vec ; 
int use[303030] ;

int main(){
    fast_input_output
    cin >> s >> t >> m ;
    n = s + t ;
    rep(i,m){
        int u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    rrep(i,s,n){
        int a, b;
        int v = i ;
        for(int k : G[v]) use[k]++ ;
        rrep(j,i+1,n){
            int cnt = 0 ;
            int u = j ;
            for(int k : G[u]) {
                if(use[k] == 1 && cnt == 0){
                    cnt++ ;
                    a = k ;
                }
                else if(use[k] == 1 && cnt == 1){
                    cnt++ ;
                    b = k ;
                    cout << a + 1 << " " << v + 1 << " " << b + 1 << " " << u + 1 << endl ;
                    return 0 ;
                }
            }
        }
        for(int k : G[v]) use[k]-- ;
    }
    cout << -1 << endl ;
}