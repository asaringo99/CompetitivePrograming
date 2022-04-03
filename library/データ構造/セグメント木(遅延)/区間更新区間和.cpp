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

    vector<T> dat , lazy ;
    int n ;
    LazySegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        dat.resize(2*n-1,0) ;
        lazy.resize(2*n-1,-inf) ;
    }

    // 遅延評価
    void eval(int k){
        if(lazy[k] == inf) return ;
        if(k < n - 1){
            lazy[2 * k + 1] = lazy[k] / 2 ;
            lazy[2 * k + 2] = lazy[k] / 2 ;
        }
        dat[k] = lazy[k] ;
        lazy[k] = inf ;
    }

    // 区間加算
    void sub_update(int a , int b , int k , int  l , int r , T w){
        eval(k) ;
        if(b <= l || r <= a) return ;
        if(a <= l && r <= b) {
            // 区間加算
            lazy[k] = (r - l) * w ;
            eval(k) ;
            return ;
        }
        sub_update(a,b,2*k+1,l,(l+r)/2,w) ;
        sub_update(a,b,2*k+2,(l+r)/2,r,w) ;
        // 区間の更新をする必要がある
        dat[k] = dat[2*k+1] + dat[2*k+2] ;
    }
    void update(int a , int b , T x){
        return sub_update(a,b,0,0,n,x) ;
    }

    T sub_sum(int a , int b , int k , int l , int r){
        //遅延評価（これは確実に必要）
        eval(k) ;
        if(b <= l || r <= a) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_sum(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_sum(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }

    T sum(int a , int b){
        return sub_sum(a,b,0,0,n)  ;
    }
};

int main(){
    int q ;
    cin >> n >> q ;
    LazySegmentTree<ll> LST(n) ;
    rep(i,q){
        int query , s , t ;
        cin >> query >> s >> t ;
        s-- ;
        if(query == 1){
            cout << LST.sum(s,t) << endl ;
        }
        else{
            ll x ;
            cin >> x ;
            LST.update(s,t,x) ;
        }
    }
}