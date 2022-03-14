#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll H , W , n ;
map<P,bool> mp , used ;
P X[101010] ;
ll res[10] ;

int main(){
    cin >> H >> W >> n ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        a-- , b--  ;
        X[i] = P(a,b) ;
        mp[P(a,b)] = true ;
    }
    res[0] = (H - 2) * (W - 2) ;
    rep(i,n){
        int x = X[i].first , y = X[i].second ;
        rep(mx,3) rep(my,3){
            int sx = x - mx , sy = y - my ;
            if(sx < 0 || sy < 0) continue ;
            if(used[P(sx,sy)]) continue ;
            used[P(sx,sy)] = true ;
            ll sum = 0 ;
            bool ok = true ;
            rep(dx,3) rep(dy,3){
                int nx = sx + dx , ny = sy + dy ;
                if(nx >= H || ny >= W) ok = false ;
                if(mp[P(nx,ny)]) sum++ ;
            }
            if(ok){
                res[0]-- ;
                res[sum]++ ;
            }
        } 
    }
    rep(i,10) cout << res[i] << endl ;
}