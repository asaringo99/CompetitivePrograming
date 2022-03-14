#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k , m ;
vector<ll> A ;
bool dp[5050][5050] ;

bool f(ll x){
    memset(dp,0,sizeof(dp)) ;
    dp[0][0] = 1 ;
    ll val = A[x] ;
    A[x] = 0 ;
    rep(i,m){
        rep(j,k){
            dp[i+1][j] |= dp[i][j] ;
            if(j+A[i] < k) dp[i+1][j+A[i]] |= dp[i][j] ;
        }
    }
    A[x] = val ;
    vector<int> sp ;
    rep(i,k) if(dp[m][i]) sp.push_back(i) ;
    sp.push_back(1e8) ;
    auto it = lower_bound(sp.begin(),sp.end(),k-A[x]) ;
    return *it != 1e8 ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        if(a < k) A.push_back(a) ;
    }
    sort(A.begin(),A.end()) ;
    m = A.size() ;
    int lef = 0 , rig = m ;
    while(rig - lef > 0){
        int mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid + 1 ;
    }
    cout << lef << endl ;
}