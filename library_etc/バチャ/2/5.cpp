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

ll H , W , m ;
P X[303030] ;
P Y[303030] ;
map<P,bool> mp ;

int main(){
    cin >> H >> W >> m ;
    rep(i,m){
        int h , w ;
        cin >> h >> w ;
        h-- ; w-- ;
        X[h] = P(X[h].first+1,h) ;
        Y[w] = P(Y[w].first+1,w) ;
        mp[P(h,w)] = true ;
    }
    sort(Y,Y+W,greater<P>()) ;
    sort(X,X+H,greater<P>()) ;
    ll res = 0 ;
    ll xval = X[0].first , yval = Y[0].first ;
    int i = 0 ;
    while(i < H && X[i].first == xval){
        int x = X[i].second ;
        int j = 0 ;
        while(j < W && Y[j].first == yval){
            int y = Y[j].second ;
            if(mp[P(x,y)]) chmax(res,xval+yval-1) ;
            if(!mp[P(x,y)]) {
                chmax(res,xval+yval) ;
                cout << res << endl ;
                return 0 ;
            }
            j++ ;
        }
        i++ ;
    }
    cout << res << endl ;
}