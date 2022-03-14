#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , m ;
ll A[101010] , S[101010] ;

P f(ll x){
    ll sum = 0 , res = 0 ;
    rep(i,n){
        ll a = A[i] ;
        auto it = lower_bound(A,A+n,x-a) ;
        int id = it - A ;
        sum += n - id ;
        res += S[n] - S[id] + (n - id) * A[i] ;
    }
    return P(sum,res) ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    rep(i,n) S[i+1] = S[i] + A[i] ;
    ll lef = 0 , rig = 1e16 ;
    P res = P(-1,-1) ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        P p = f(mid) ;
        if(p.first >= m){
            lef = mid ;
            res = p ;
        }
        else rig = mid ;
    }
    ll ans = res.second - (res.first - m) * lef ;
    cout << ans << endl ;
}