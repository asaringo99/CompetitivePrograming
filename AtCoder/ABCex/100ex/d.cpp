#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll X[1010] , Y[1010] , Z[1010] ;

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> X[i] >> Y[i] >> Z[i] ;
    ll res = 0 ;
    rep(x,2) rep(y,2) rep(z,2){
        vector<ll> vec ;
        rep(i,n){
            ll sum = 0 ;
            sum += x == 0 ? -X[i] : X[i] ;
            sum += y == 0 ? -Y[i] : Y[i] ;
            sum += z == 0 ? -Z[i] : Z[i] ;
            vec.push_back(sum) ;
        }
        sort(vec.begin(),vec.end(),greater<ll>()) ;
        ll val = 0 ;
        rep(i,m) val += vec[i] ;
        chmax(res,val) ;
    }
    cout << res << endl ;
}