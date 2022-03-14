#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , k ;
ll A[202020] , F[202020] ;

bool f(ll x){
    ll sum = 0 ;
    rep(i,n){
        sum += max(0LL,A[i] - x / F[i]) ;
        if(sum > k) return false ;
    }
    return sum <= k ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> F[i] ;
    sort(F,F+n,greater<ll>()) ;
    sort(A,A+n) ;
    ll lef = 0 , rig = 1e18 ;
    while(rig - lef > 0){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid + 1 ;
    }
    cout << rig << endl ;
}