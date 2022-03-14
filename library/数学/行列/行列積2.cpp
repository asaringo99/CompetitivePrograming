#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;

vector<vector<ll>> mat(vector<vector<ll>> X , vector<vector<ll>> Y){
    int x = X.size() , y = Y[0].size() , n = Y.size() ;
    vector<vector<ll>> res(x,vector<ll>(y)) ;
    rep(i,x) rep(j,y) rep(k,n) {
        (res[i][j] += X[i][k] * Y[k][j]) %= mod ;
    }
    return res ;
}