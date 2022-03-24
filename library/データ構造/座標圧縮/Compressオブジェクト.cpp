#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

// 座標圧縮
struct Compress{
    vector<int> vec ; // 元の値の座標圧縮後の値
    unordered_map<ll,ll> mp ; // 元の値がどの値に変換されたか
    Compress(vector<int> A){
        int n = A.size() ;
        vector<int> B(n) ;
        for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        sort(A.begin(),A.end()) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(A.begin(),A.end(),B[i]) ;
            vec[i] = it - A.begin() ;
            mp[B[i]] = it - A.begin();
        }
    }
    size_t size() {return vec.size() ; }
    inline int at(ll i) { return mp[i] ; }
    inline int operator [] (int i) { return vec[i] ; }
};


int main(){
    vector<int> B = {3,4,5,6,3456,3215,392348,41,34,3143} ;
    Compress sit(B) ;
    rep(i,10) cout << sit[i] << " " ; cout << endl ;
}