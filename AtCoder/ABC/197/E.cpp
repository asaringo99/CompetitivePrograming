#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

int main(){
    cin >> n ;
    map<ll,set<ll>> rem ;
    ll C = 0 ;
    for(int i = 0 ; i < n ; i++){
        ll x , c ;
        cin >> x >> c ;
        //x += 1e9 ;
        rem[c].insert(x) ;
        C = max(C,c) ;
    }
    ll res = 0 ;
    ll tmp = 0 ;
    ll dp[C+1][2] ;
    int k = 1 ;
    while(rem[k].empty()) k++ ;
    auto it = rem[k].begin() ;
    ll bf_fir = *it ;
    it = rem[k].end() ;
    it-- ;
    ll bf_fin = *it ;
    dp[k][0] = abs(bf_fin) + (bf_fin - bf_fir) ;
    dp[k][1] = abs(bf_fir) + (bf_fin - bf_fir) ;
    ll ans , mag = 0 ;
    for(int i = k + 1 ; i < C + 1 ; i++){
        if(rem[k].empty()) {
            mag++ ;
            continue ;
        }
        auto it = rem[i].begin() ;
        ll fir = *it ;
        it = rem[i].end() ;
        it-- ;
        ll fin = *it ;
        dp[i][0] = min(dp[i-1-mag][0] + abs(bf_fir - fin) + abs(fin - fir) , dp[i-1-mag][1] + abs(bf_fin - fin) + abs(fin - fir)) ;
        dp[i][1] = min(dp[i-1-mag][0] + abs(bf_fir - fir) + abs(fin - fir) , dp[i-1-mag][1] + abs(bf_fin - fir) + abs(fin - fir)) ;
        if(i == C){
            ans = min(dp[C][0] + abs(fir), dp[C][1] + abs(fin)) ;
        }
        bf_fir = fir ;
        bf_fin = fin ;
        mag = 0 ;
    }
    cout << ans << endl ;
    set<int> ss = {1,2} ;
    auto ir = ss.end() ;
    //ir-- ;
    int iii = *ir ;
    cout << iii << endl ;
}