#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
ll A[202020] , S[202020] ;
map<ll,ll> mp ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] , S[i+1] = S[i] + A[i] ;
    mp[0]++ ;
    ll res = 0 ;
    rrep(i,1,n+1){
        if(i >= k){
            mp[(S[i-k]-(i-k))%k]-- ;
        }
        res += mp[(S[i]-i)%k] ;
        mp[(S[i]-i)%k]++ ;
    }
    cout << res << endl ;
}