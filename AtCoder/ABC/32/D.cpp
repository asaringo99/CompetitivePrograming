#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll W ;
ll v[220] , w[220] ;
ll dp[220][202020] ;

struct nupsuck{

    ll nupsuck_W(){
        rep(i,n) rep(j,min(202020LL,W+1)){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]) ;
            if(j + w[i] > min(W,202020LL)) continue ;
            dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j]+v[i]) ;
        }
        return dp[n][min(W,202000LL)] ;
    }

    ll nupsuck_V(){
        ll res = -1 ;
        rep(i,n+1) rep(j,202020) dp[i][j] = 1e17 ;
        dp[0][0] = 0 ;
        rep(i,n) rep(j,202020){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]) ;
            if(dp[i][j] + w[i] > W) continue ;
            if(j + v[i] > 202020) continue ;
            dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]],dp[i][j]+w[i]) ;
        }
        rep(i,202020) if(dp[n][i] <= W) res = i ;
        return res ;
    }

    ll nupsuck_N(){
        vector<P> sp , fp ;
        int m = n / 2 , k = n - m ;
        rep(i,1<<m){
            ll weigh = 0 , value = 0 ;
            rep(j,m) if(i >> j & 1){
                weigh += w[j] ;
                value += v[j] ;
            }
            if(weigh > W) continue ;
            sp.push_back(P(weigh,value)) ;
        }
        sp.push_back(P(0,0)) ;
        sp.push_back(P(1e17,-1e17)) ;
        sort(sp.begin(),sp.end()) ;
        rep(i,sp.size()-1) if(sp[i].second >= sp[i+1].second) sp[i+1] = sp[i] ;
        ll res = -1 ;
        rep(i,1<<k){
            ll weigh = 0 , value = 0 ;
            rep(j,k) if(i >> j & 1){
                weigh += w[m+j] ;
                value += v[m+j] ;
            }
            if(weigh > W) continue ;
            auto it = upper_bound(sp.begin(),sp.end(),P(W-weigh,1e17)) ;
            it-- ;
            if(weigh + it->first <= W) res = max(res,value+it->second) ;
        }
        return res ;
    }
};


int main(){
    nupsuck NP ;
    cin >> n >> W ;
    ll maxv = -1 , maxw = -1 ;
    rep(i,n){
        cin >> v[i] >> w[i] ;
        maxv = max(maxv,v[i]) ;
        maxw = max(maxw,w[i]) ;
    }
    if(n <= 30) cout << NP.nupsuck_N() << endl ;
    else if(maxv <= 1000) cout << NP.nupsuck_V() << endl ;
    else cout << NP.nupsuck_W() << endl ;
}