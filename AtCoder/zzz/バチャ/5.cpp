#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int MAX_N = 1 << 18 ;

template<typename T>
struct BinaryIndexedTree {

    T bit[MAX_N + 1] ; //bit[0] = 0
    int n ;
    
    //コンストラクタ
    BinaryIndexedTree(int n_){
        n = n_ ;
        memset(bit,0,sizeof(bit)) ;
    }
    //加算
    void add(T i , T x){
        while(i <= n){
            bit[i] += x ;
            i += i & -i ;
        }
    }
    //総和
    T sum(int i){
        T s = 0 ;
        while(i > 0){
            s += bit[i] ;
            i -= i & -i ; // iから(i & -i)を引く
        }
        return s ;
    }
    //区間和
    T secsum(int i , int j){
        return sum(j-1) - sum(i-1) ;
    }
    //二分探索
    T lower_bound(T x){
        if(x <= 0) return 0 ;
        int lef = 0 , rig = 1 ;
        while(rig < n) rig *= 2 ;
        while(rig > 0){
            if(lef + rig <= n && bit[lef + rig] < x){
                x -= bit[lef + rig] ;
                lef += rig ;
            }
            rig >>= 1 ;
        }
        return lef + 1 ;
    }

    //転倒数計算
    T inversion(T *A , int n_){
        T s = 0 ;
        for(int i = 0 ; i < n_ ; i++){
            s += i - sum(A[i]) ;
            add(A[i],1) ;
        }
        return s ;
    }
};

ll n , m , x ;
ll A[404040] , B[404040] ;
set<ll> st ;
map<ll,ll> mp ;

int main(){
    cin >> n >> m >> x ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    BinaryIndexedTree<ll> bit(n+1) ;
    rep(i,n) bit.add(i+1,A[i]) ;
    ll res = 0 , sum = 0 ;
    ll lef = 0 , rig = 0 ;
    while(rig < n){
        while(rig < n && st.size() != m){
            sum += A[rig] ;
            st.insert(B[rig]) ;
            mp[B[rig]]++ ;
            rig++ ;
        }
        while(st.size() == m){
            sum -= A[lef] ;
            mp[B[lef]]-- ;
            if(mp[B[lef]] == 0) st.erase(B[lef]) ;
            lef++ ;
        }
        ll v = bit.secsum(lef,rig+1) ;
        cout << lef << " " << rig << " " << v << endl ;
        if(v < x){
            ll k = x - v ;
            ll l = 0 , r = lef + 1 ;
            while(r - l > 1){
                ll mid = (l + r) / 2 ;
                if(bit.secsum(lef-mid,lef) <= k) l = mid ;
                else r = mid ;
            }
            res += l == 0 ? 1 : l ;
            cout << l << " " << res << endl ;
        }
    }
    cout << res << endl ;
}