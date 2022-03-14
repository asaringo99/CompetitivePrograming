#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 101010 ;

template<typename T>
struct UnionFind {
    T par[MAX_N] ; //親
    T lank[MAX_N] ; //木の深さ
    T volume[MAX_N] ; //木のサイズ
    UnionFind(T n){
        //n要素で初期化
        for(int i = 0 ; i < n ; i++){
            par[i] = i ;
            lank[i] = 0 ;
            volume[i] = 1 ;
        }
    }
    //木の根を求める
    T root(T x){
        if(par[x] == x){
            return x ;
        } else{
            return par[x] = root(par[x]) ;
        }
    }

    //xとyの属する集合を合併
    void unite(T x , T y){
        x = root(x);
        y = root(y) ;
        if(x == y) return ;

        if(lank[x] < lank[y]){
            par[x] = y ;
            volume[y] += volume[x] ;
        } else {
            par[y] = x ;
            if(lank[x] == lank[y]) lank[x]++ ;
            volume[x] += volume[y] ;
        }
    }

    bool same(T x , T y){
        return root(x) == root(y) ;
    }

    T size(T x){
        return volume[root(x)] ;
    }
} ;

int n , m , q ;
TP X[202020] ;
TP Y[101010] ;
int res[101010] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b , y ;
        cin >> a >> b >> y ;
        a-- ; b-- ;
        X[i] = {y,a,b} ;
    }
    cin >> q ;
    rep(i,q){
        int v , w ;
        cin >> v >> w ;
        v-- ;
        Y[i] = {w,v,i} ;
    }
    UnionFind<ll> UF(n) ;
    sort(X,X+m,greater<TP>()) ;
    sort(Y,Y+q,greater<TP>()) ;
    int t = 0 ;
    rep(i,q){
        int w , v , id ;
        tie(w,v,id) = Y[i] ;
        int j = t ;
        while(true){
            int y , a , b ;
            tie(y,a,b) = X[j] ;
            if(j == m || y <= w) break ;
            j++ ;
            t = j ;
            UF.unite(a,b) ;
        }
        res[id] = UF.size(v) ;
    }
    rep(i,q) cout << res[i] << endl ;
}