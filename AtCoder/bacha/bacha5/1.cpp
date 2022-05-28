#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n ;

int main(){
    fast_input_output
    cin >> n ;
    vector<int> A(n) , B ;
    set<int> st ;
    rep(i,n) cin >> A[i] ;
    for(int a : A) st.insert(a) ;
    for(int a : st) B.push_back(a) ;
    Compress sit(B) ;
    rep(i,n) cout << sit.at(A[i]) << endl ;
}