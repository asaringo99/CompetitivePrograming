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
vector<int> X[101010] , A[101010] ;

int main(){
    fast_input_output
    cin >> n >> m ;
    rep(i,n) {
        int x , y ;
        cin >> x >> y ;
        x-- ; y-- ;
        X[x].push_back(y) ;
    }
    rep(i,m) {
        int a ;
        cin >> a ;
        a-- ;
        A[a].push_back(a) ;
    }
    ll sum = 0 ;
    priority_queue<int,vector<int>,greater<int>> que ;
    int res = 0 ;
    rep(i,101010){
        for(int u : X[i]) que.push(u) ;
        for(int u : A[i]){
            while(!que.empty()){
                int v = que.top() ; que.pop() ;
                if(u <= v) {
                    res++ ;
                    break;
                }
            }
        }
    }
    cout << res << endl ;
}