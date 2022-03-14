#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ld,ld> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const ld eps = 1e-8 ;

template<typename T>
struct SegmentTree{
    int n ;
    vector<T> dat ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        dat.resize(2 * n - 1,0) ;
    }
    void add(int k , T x){
        k += n - 1 ;
        dat[k] += x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
    T binary_search(int k){
        ll lef = 0 , rig = n ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(query(0,mid) < k) lef = mid ;
            else rig = mid ;
        }
        return rig ;
    }
};

int n , m , k ;
int A[101010] ;
P dp[101010] ;

int main(){
    cin >> n >> m >> k ;
    rep(i,k){
        int a ;
        cin >> a ;
        A[a]++ ;
    }
    SegmentTree<ld> x(n+m) , a(n+m) ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(A[i] == 1){
            x.add(i,1) ;
        }
        else{
            ld y = x.query(i+1,i+1+m) ;
            ld b = a.query(i+1,i+1+m) ;
            x.add(i,y/m) ;
            a.add(i,b/m+1) ;
        }
    }
    ld v = 1 - x.query(0,1) ;
    if(abs(v) < eps){
        cout << -1 << endl ;
        return 0 ;
    }
    ld res = a.query(0,1) / v ;
    cout << fixed << setprecision(25) << res << endl ;
}