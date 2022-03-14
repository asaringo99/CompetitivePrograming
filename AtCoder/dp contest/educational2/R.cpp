#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

ll n , k ;
vector<vector<ll>> dp(55) , A(55,vector<ll>(55)) ;

vector<vector<ll>> mat(vector<vector<ll>> X , vector<vector<ll>> Y){
    int x = X.size() , y = Y[0].size() , n = Y.size() ;
    vector<vector<ll>> res(x,vector<ll>(y)) ;
    rep(i,x) rep(j,y) rep(k,n) {
        (res[i][j] += X[i][k] * Y[k][j]) %= mod ;
    }
    return res ;
}

ll doubling(vector<vector<ll>> A , ll k){
    vector<vector<ll>> res(n,vector<ll>(1,1)) ;
    while(k > 0){
        if(k & 1) res = mat(A,res) ;
        A = mat(A,A) ;
        k >>= 1 ;
    }
    ll val = 0 ;
    rep(i,n) (val += res[i][0]) %= mod ;
    return val ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) rep(j,n) cin >> A[j][i] ;
    cout << doubling(A,k) << endl ;
}