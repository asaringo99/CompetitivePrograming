#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll n , k ;
unordered_map<ll,ll> mp , inv ;
vector<ll> vec ;
ll dp[107][101010] , S[101010] ;

int main(){
    cin >> n >> k ;
    vec.push_back(0) ;
    for(ll i = 1 ; i * i <= n ; i++){
        vec.push_back(i) ;
        inv[i] = n / i ;
        inv[n / i] = i ;
        if(i != n / i) vec.push_back(n / i) ;
    }
    sort(vec.begin(),vec.end()) ;
    int m = vec.size() ;
    rrep(i,1,m) mp[vec[i]] = i ;
    rrep(i,1,m) dp[1][i] = vec[i] - vec[i-1] ;
    rrep(i,1,k){
        ll sum = 0 ;
        rrep(j,1,m){
            (sum += dp[i][j]) %= mod ;
            dp[i+1][m-j] = sum * (vec[mp[inv[vec[j]]]] - vec[mp[inv[vec[j]]]-1]) % mod ;
        }
    }
    ll res = 0 ;
    rrep(i,1,m) (res += dp[k][i]) %= mod ;
    cout << res << endl ;
}