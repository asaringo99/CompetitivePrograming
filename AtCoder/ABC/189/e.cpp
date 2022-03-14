#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m , q ;
ll X[202020] , Y[202020] ;
vector<P> query[202020] ;
P ope[202020] ;
P res[202020] ;

vector<vector<ll>> g(vector<vector<ll>> A , vector<vector<ll>> x){
    int n = A.size() , m = x[0].size() ;
    vector<vector<ll>> res(n,vector<ll>(m,0)) ;
    rep(i,n) rep(j,m) rep(k,x.size()) res[i][j] += A[i][k] * x[k][j] ;
    return res ;
}

vector<vector<ll>> f(int t , ll p , vector<vector<ll>> X) {
    vector<vector<ll>> A , B , C , D ;
    A = {{0,1,0},{-1,0,0},{0,0,1}} ;
    B = {{0,-1,0},{1,0,0},{0,0,1}} ;
    C = {{-1,0,2*p},{0,1,0},{0,0,1}} ;
    D = {{1,0,0},{0,-1,2*p},{0,0,1}} ;
    if(t == 1) return g(A,X) ;
    else if(t == 2) return g(B,X) ;
    else if(t == 3) return g(C,X) ;
    else return g(D,X) ;
};

int main(){
    cin >> n ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    cin >> m ;
    rep(i,m){
        int t ;
        cin >> t ;
        if(t == 1 || t == 2) ope[i] = P(t,-1) ;
        if(t == 3 || t == 4){
            ll x ;
            cin >> x ;
            ope[i] = P(t,x) ;
        }
    }
    cin >> q ;
    rep(i,q){
        ll a , b ;
        cin >> a >> b ;
        query[a].push_back(P(b-1,i)) ;
    }
    vector<vector<ll>> V = {{1,0,0},{0,1,0},{0,0,1}} ;
    rep(i,m+1){
        int t = ope[i].first , p = ope[i].second ;
        for(P p : query[i]){
            int u = p.first , id = p.second ;
            vector<vector<ll>> x = {{X[u]},{Y[u]},{1}} ;
            vector<vector<ll>> vec = g(V,x) ;
            res[id] = P(vec[0][0],vec[1][0]) ;
        }
        if(i != m) V = f(t,p,V) ;
    }
    rep(i,q) cout << res[i].first << " " << res[i].second << endl ;
}