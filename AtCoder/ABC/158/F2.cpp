#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 998244353 ;
const int MAX_N = 1 << 18 ;

struct SegTree{
    int n = 1 ;
    int dat[MAX_N * 2 - 1] ;

    SegTree(int n_){
        memset(dat,0,sizeof(dat)) ;
        while(n < n_) n *= 2 ;
        for(int i = 0 ; i < n ; i++) dat[n - 1 + i] = i ;
    }

    void update(int v , int x){
        v += n - 1 ;
        dat[v] = x ;
        while(v > 0){
            v = (v - 1) / 2 ;
            dat[v] = max(dat[2*v+1],dat[2*v+2]) ;
        }
    }

    int sub_query(int a , int b , int k , int l , int r){
        if(b <= l || r <= a) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        int lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        int rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }

    int query(int l , int r){
        return sub_query(l,r,0,0,n) ;
    }
};

int n ;
ll dp[202020] ;
P XD[202020] ;
vector<ll> X ;
vector<ll> D ;

int main(){
    cin >> n ;
    rep(i,n) cin >> XD[i].first >> XD[i].second ;
    sort(XD,XD+n) ;
    rep(i,n){
        X.push_back(XD[i].first) ;
        D.push_back(XD[i].second) ;
    }
    SegTree seg(n) ;
    dp[n] = 1 ;
    rep(i,n){
        ll x = X[n-1-i] , d = D[n-1-i] ;
        auto it = lower_bound(X.begin(),X.end(),x+d) ;
        it-- ;
        int id = it - X.begin() ;
        int v = seg.query(n-1-i,id+1) ;
        seg.update(n-1-i,v) ;
        dp[n-1-i] = (dp[n-i]+dp[v+1]) % mod ;
    }
    cout << dp[0] << endl ;
}