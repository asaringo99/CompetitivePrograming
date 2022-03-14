#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,bool> P ;
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
vector<P> vec[20] ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        rep(j,a){
            int x , y ;
            cin >> x >> y ;
            x-- ;
            vec[i].push_back(P(x,y)) ;
        }
    }
    int res = 0 ;
    rep(S,1<<n){
        bool use[20] ;
        memset(use,0,sizeof(use)) ;
        rep(i,n) if(S >> i & 1) use[i] = true ;
        bool ok = true ;
        rep(i,n){
            int a = vec[i].size() ;
            if(use[i]) rep(j,a){
                int x = vec[i][j].first , y = vec[i][j].second ;
                if(use[x] != y) ok = false ;
            }
        }
        if(ok) chmax(res,bit_count(S)) ;
    }
    cout << res << endl ;
}