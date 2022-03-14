#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int MAX_N = 1 << 19 ;

template<typename T>
struct LazySegmentTree{
    T data[2 * MAX_N - 1] , lazy[2 * MAX_N - 1] ;
    int n ;
    LazySegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(data,0,sizeof(data)) ;
        memset(lazy,0,sizeof(lazy)) ;
    }

    // 遅延評価
    void eval(int k){
        data[k] += lazy[k] ;
        if(k < n - 1){
            lazy[2 * k + 1] += lazy[k] / 2 ;
            lazy[2 * k + 2] += lazy[k] / 2 ;
        }
        lazy[k] = 0 ;
    }

    // 区間加算
    void sub_add(int a , int b , int k , int  l , int r , T w){
        eval(k) ;
        if(b <= l || r <= a) return ;
        if(a <= l && r <= b) {
            // 区間加算
            lazy[k] += (r - l) * w ;
            eval(k) ;
            return ;
        }
        sub_add(a,b,2*k+1,l,(l+r)/2,w) ;
        sub_add(a,b,2*k+2,(l+r)/2,r,w) ;
        // 区間の更新をする必要がある
        data[k] = data[2*k+1] + data[2*k+2] ;
    }
    void add(int a , int b , T x){
        return sub_add(a,b,0,0,n,x) ;
    }

    T sub_sum(int a , int b , int k , int l , int r){
        //遅延評価（これは確実に必要）
        eval(k) ;
        if(b <= l || r <= a) return 0 ;
        if(a <= l && r <= b) return data[k] ;
        T lef = sub_sum(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_sum(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }

    T sum(int a , int b){
        return sub_sum(a,b,0,0,n)  ;
    }
};

int n , m ;
vector<int> sec[101010] ;

int main(){
    cin >> n >> m ;
    LazySegmentTree<ll> LST(m+1) ; 
    rep(i,n){
        int l , r ;
        cin >> l >> r ;
        r++ ;
        sec[r-l].push_back(l) ;
    }
    int sum = 0 ;
    rrep(i,1,m+1){
        int res = n - sum ;
        for(int j = 0 ; j <= m ; j += i) res += LST.sum(j,j+1) ;
        for(int u : sec[i]) LST.add(u,u+i,1) , sum++ ;
        cout << res << endl ;
    }
}