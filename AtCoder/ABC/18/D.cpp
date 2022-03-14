#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m , p , q , r ;

struct edge
{
    int to ;
    ll cost ;
};


const int MAX_N = 1007 ;
vector<edge> G[20] , Z[20] ;

int main(){
    cin >> n >> m >> p >> q >> r ;
    rep(i,r) {
        int x , y , z ;
        cin >> x >> y >> z ;
        x-- ;
        y-- ;
        G[x].push_back(edge{y,z}) ;
    }
    ll res = -1 ;
    for(int i = 0 ; i < 1 << n ; i++){
        int count = 0 ;
        int BOY[20] ;
        memset(BOY,0,sizeof(BOY)) ;
        vector<int> vec ;
        for(int j = 0 ; j < n ; j++) if(i >> j & 1) vec.push_back(j) ;
        if(vec.size() != p) continue ;
        for(int u : vec){
            for(edge e : G[u]){
                BOY[e.to] += e.cost ;
            }
        }
        sort(BOY,BOY+m,greater<int>()) ;
        ll val = 0 ;
        for(int i = 0 ; i < q ; i++) val += BOY[i] ;
        res = max(res,val) ;
    }
    cout << res << endl ;
}