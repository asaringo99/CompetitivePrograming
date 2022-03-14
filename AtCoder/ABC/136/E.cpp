#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> P ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
ll A[505] ;
vector<int> fac ;

int main(){
    cin >> n >> k ;
    ll sum = 0 ;
    rep(i,n) cin >> A[i] , sum += A[i] ;
    for(ll i = 1 ; i * i <= sum ; i++){
        if(sum % i == 0){
            fac.push_back(i) ;
            if(i * i != sum) fac.push_back(sum/i) ;
        }
    }
    int m = fac.size() ;
    ll res = 1 ;
    rep(i,m){
        ll mod = fac[i] ;
        vector<ll> vec ;
        rep(j,n) vec.push_back(A[j]%mod) ;
        sort(vec.begin(),vec.end()) ;
        ll u[505] , d[505] ;
        memset(u,0,sizeof(u)) ;
        memset(d,0,sizeof(d)) ;
        rep(j,n){
            d[j+1] = d[j] + vec[j] ;
            u[j+1] = u[j] + mod - vec[j] ;
        }
        ll sum = 1e18 ;
        rrep(j,1,n+1) sum = min(sum,max(d[j],u[n]-u[j])) ;
        if(sum <= k) res = max(res,mod) ;
    }
    cout << res << endl ;
}