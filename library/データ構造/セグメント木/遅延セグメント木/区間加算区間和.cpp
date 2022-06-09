#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

template<typename T>
struct LazySegmentTree{
    private :
        const ll linf = 1e18 ;
        const int inf = 1e8 ;

        int n , n_ ;
        vector<T> dat , lazy ;

        void build(){
            n = 1 ;
            while(n < n_) n *= 2 ;
            dat.resize(2*n-1,0) ;
            lazy.resize(2*n-1,0) ;
        }

        // 遅延評価
        void eval(int k){
            dat[k] += lazy[k] ;
            if(k < n - 1){
                lazy[2 * k + 1] += lazy[k] / 2 ;
                lazy[2 * k + 2] += lazy[k] / 2 ;
            }
            lazy[k] = 0 ;
        }

        // 区間加算
        void add_(int a , int b , int k , int  l , int r , T w){
            eval(k) ;
            if(b <= l || r <= a) return ;
            if(a <= l && r <= b) {
                // 区間加算
                lazy[k] += (r - l) * w ;
                eval(k) ;
                return ;
            }
            add_(a,b,2*k+1,l,(l+r)/2,w) ;
            add_(a,b,2*k+2,(l+r)/2,r,w) ;
            // 区間の更新をする必要がある
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
        void add_(int a , int b , T x){
            return add_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            //遅延評価（これは確実に必要）
            eval(k) ;
            if(b <= l || r <= a) return 0 ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return lef + rig ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n)  ;
        }

    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void add(int a , int b , T x) { add_(a,b,x) ; }
};

int n , q ;

// verified : https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G

int main(){
    cin >> n >> q ;
    LazySegmentTree<ll> LST(n) ;
    rep(i,q){
        int query , s , t ;
        cin >> query >> s >> t ;
        s-- ;
        if(query == 1){
            cout << LST.query(s,t) << endl ;
        }
        else{
            ll x ;
            cin >> x ;
            LST.add(s,t,x) ;
        }
    }
}