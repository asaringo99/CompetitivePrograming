#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
ll A[1010] ;
vector<ll> ad , vec[101] , arr ;
map<ll,bool> mp ;
ll B[101] ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    rep(i,n){
        ll sum = 0 ;
        rrep(j,i,n){
            sum += A[j] ;
            ad.push_back(sum) ;
        }
    }
    for(ll u : ad){
        rep(i,60) if(u >> i & 1) {
            vec[i].push_back(u) ;
        }
    }
    int s = -1 ;
    for(int i = 60 ; i >= 0 ; i--){
        if(vec[i].size() >= k){
            s = i ;
            for(ll u : vec[i])  arr.push_back(u) ;
            break ;
        }
    }
    if(arr.empty()){
        cout << 0 << endl ;
        return 0 ;
    }
    for(int i = s ; i >= 0 ; i--){
        vector<ll> use ;
        for(ll u : arr){
            if(u >> i & 1) use.push_back(u) ;
        }
        if(use.size() >= k) arr = use ;
    }
    ll sum = (1LL << 60) - 1 ;
    rep(i,k) sum &= arr[i] ;
    cout << sum << endl ;
}