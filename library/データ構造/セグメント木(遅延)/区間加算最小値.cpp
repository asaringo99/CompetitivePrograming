#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

template<typename T>
struct LazySegmentTree{
    const ll linf = 1e18 ;
    const int inf = 1e8 ;

    int n ;
    vector<T> dat , lazy ;
    LazySegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        dat.resize(2*n-1,0) ;
        lazy.resize(2*n-1,0) ;
    }

    // 遅延評価
    void eval(int k){
        data[k] += lazy[k] ;
        if(k < n - 1){
            lazy[2 * k + 1] += lazy[k] ;
            lazy[2 * k + 2] += lazy[k] ;
        }
        lazy[k] = 0 ;
    }

    // 区間加算
    void sub_add(int a , int b , int k , int  l , int r , T w){
        eval(k) ;
        if(b <= l || r <= a) return ;
        if(a <= l && r <= b) {
            // 区間加算
            lazy[k] += w ;
            eval(k) ;
            return ;
        }
        sub_add(a,b,2*k+1,l,(l+r)/2,w) ;
        sub_add(a,b,2*k+2,(l+r)/2,r,w) ;
        // 区間の更新をする必要がある
        data[k] = min(data[2*k+1],data[2*k+2]) ;
    }
    void add(int a , int b , T x){
        return sub_add(a,b,0,0,n,x) ;
    }

    T sub_query(int a , int b , int k , int l , int r){
        //遅延評価（これは確実に必要）
        eval(k) ;
        if(b <= l || r <= a) return inf ;
        if(a <= l && r <= b) return data[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return min(lef,rig) ;
    }

    T query(int a , int b){
        return sub_query(a,b,0,0,n)  ;
    }
};

int main(){
    int q ;
    cin >> n >> q ;
    LazySegmentTree<ll> LST(n) ;
}