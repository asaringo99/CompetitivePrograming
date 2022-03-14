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

ll n , l , k ;
ll A[101010] ;

bool f(ll x){
    ll sta = 0 , sum = 0 ;
    rep(i,n+1){
        if(A[i] - sta >= x){
            sta = A[i] ;
            sum++ ;
        }
    }
    return sum > k ;
}

int main(){
    cin >> n >> l >> k ;
    rep(i,n) cin >> A[i] ;
    A[n] = l ;
    ll lef = 0 , rig = l ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
    }
    cout << lef << endl ;
}