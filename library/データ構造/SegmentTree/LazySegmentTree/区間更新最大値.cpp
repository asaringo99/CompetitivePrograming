#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , w ;

template <typename T>
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
            lazy.resize(2*n-1,-inf) ;
        }

        void eval(int k){
            if(lazy[k] == -inf) return ;
            if(k < n - 1){
                lazy[2*k+1] = lazy[k] ;
                lazy[2*k+2] = lazy[k] ;
            }
            dat[k] = lazy[k] ;
            lazy[k] = -inf ;
        }

        void update_(int a , int b , int k , int l , int r , T x){
            eval(k) ;
            if(r <= a || b <= l) return ;
            if(a <= l && r <= b) {
                lazy[k] = x ;
                eval(k) ;
                return ;
            }
            update_(a,b,2*k+1,l,(l+r)/2,x) ;
            update_(a,b,2*k+2,(l+r)/2,r,x) ;
            dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
        }

        void update_(int a , int b , T x){
            update_(a,b,0,0,n,x) ;
        }

        T query_(int a , int b , int k , int l , int r){
            eval(k) ;
            if(r <= a || b <= l) return -inf ;
            if(a <= l && r <= b) return dat[k] ;
            T lef = query_(a,b,2*k+1,l,(l+r)/2) ;
            T rig = query_(a,b,2*k+2,(l+r)/2,r) ;
            return max(lef,rig) ;
        }

        T query_(int a , int b){
            return query_(a,b,0,0,n) ;
        }

    public :
        LazySegmentTree(int _n) : n_(_n) { build() ; }
        T query(int a , int b) { return query_(a,b) ; }
        void update(int a , int b , T x) { update_(a,b,x) ; }
};

int n , q ;

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
            LST.update(s,t,x) ;
        }
    }
}