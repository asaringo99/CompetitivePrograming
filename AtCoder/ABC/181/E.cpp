#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12LLON
#define MAX_N 12
#define mod (ll)(1e9+7)

int n , m ;

int main(){
    cin >> n >> m ;
    ll H[n] , mag1[n] ,  mag2[n] , stc1[n / 2 + 1] , stc2[n / 2 + 1] ;
    vector<ll> W(m) ;
    stc1[0] = 0 ; stc2[0] = 0 ;
    for(int i = 0 ; i < n ; i++) cin >> H[i] ;
    sort(H,H+n) ;
    for(int j = 0 ; j < m ; j++) cin >> W[j] ;
    sort(W.begin(),W.end()) ;
    for(int i = 0 ; i < n / 2 + 1 ; i++){
        mag1[i] = H[2 * i + 1] - H[2 * i] ;
    }
    for(int i = 0 ; i < n / 2 ; i++){
        mag2[i] = H[2 * i + 2] - H[2 * i + 1] ;
    }
    for(int i = 0 ; i < n / 2 ; i++){
        stc1[i+1] = stc1[i] + mag1[i] ;
    }
    for(int i = 0 ; i < n / 2 ; i++){
        stc2[i+1] = stc2[i] + mag2[i] ;
    }
    ll ans = LLONG_MAX ;
    for(int i = 0 ; i < n ; i++){
        auto it = lower_bound(W.begin(),W.end(),H[i]) ;
        ll pls ;
        if(it == W.begin()) pls = abs(*it - H[i]) ;
        else pls = min(abs(*it - H[i]),abs(*(it--) - H[i])) ;
        //cout << pls << endl ;
        if(i % 2 == 0){
            ll left = stc1[i / 2] , rig = stc2[n / 2] - stc2[i / 2] ;
            ans = min(ans,left+rig+pls) ;
        }
        else{
            ll tt = H[i+1] - H[i-1] ;
            ll left = stc1[i / 2] , rig = stc2[n / 2] - stc2[i / 2 + 1] ;
            //cout << left << " " << rig << " " << tt << endl ;
            ans = min(ans,left+rig+pls+tt) ;
        }
    }
    cout << ans << endl ;
}