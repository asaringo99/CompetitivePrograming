#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

template<typename T>
struct UnionFind {
    vector<T> par ; //親
    vector<T> lank ; //木の深さ
    vector<T> volume ; //木のサイズ
    UnionFind(T n){
        //n要素で初期化
        par.resize(n) ;
        lank.resize(n) ;
        volume.resize(n) ;
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

int n ;

int main(){
    cin >> n ;
    UnionFind<int> uf(n) ;
}