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

struct Doubling {
    private:
        const ll INF = LLONG_MAX ;

        int n ;
        vector<vector<int>> dp ;
        vector<vector<ll>> S ;

        void init(vector<int> A_ , vector<ll> T) {
            n = A_.size() ;
            dp.resize(60,vector<int>(n)) ;
            S.resize(60,vector<ll>(n)) ;
            rep(i,n){
                dp[0][i] = A_[i] ;
                S[0][i] = T[i] ;
            }
        }

        void build_(int count = 59){
            rep(i,count) {
                rep(j,n) {
                    dp[i+1][j] = dp[i][dp[i][j]] ;
                    if(INF - S[i][j] <= S[i][dp[i][j]]) S[i+1][j] = INF ;
                    else S[i+1][j] = S[i][j] + S[i][dp[i][j]] ;
                }
            }
        }

        int get_index_(int v , ll k) {
            int cnt = 0 ;
            while(k > 0){
                if(k & 1) v = dp[cnt][v] ;
                cnt++ ;
                k >>= 1 ;
            }
            return v ;
        }

        ll get_sum_(int v , ll k) {
            ll sum = 0 ;
            int cnt = 0 ;
            while(k > 0){
                if(k & 1) {
                    if(INF - sum <= S[cnt][v]) sum = INF ;
                    else sum += S[cnt][v] ;
                    v = dp[cnt][v] ;
                }
                cnt++ ;
                k >>= 1 ;
            }
            return sum ;
        }

    public:
        // A[i] = j : i ??? j ???????????????
        // T[i] = x : i ??? j ?????????????????????????????????(????????????)??? x ?????????
        Doubling(vector<int> A_ , vector<ll> T = vector<ll>(202020,0)){ init(A_,T) ; }

        void build() { build_() ; }
        int get_index(int v , ll k) { return get_index_(v,k) ; }
        int get_next_moving_index(int v) { return dp[0][v] ; }
        ll get_sum(int v , ll k) { return get_sum_(v,k) ; }
        ll get_next_moving_sum(int v) { return S[0][v] ; }
};

int n , x , q ;
ll W[202020] , S[606060] ;

int main(){
    fast_input_output
    cin >> n >> q >> x ;
    rep(i,n) cin >> W[i] ;
    rep(i,3*n) S[i+1] = S[i] + W[i%n] ;
    ll total = S[n] ;
    vector<int> A(n) ;
    vector<ll> T(n) ;
    rep(i,n){
        ll s = x / total ;
        ll r = x % total ;
        auto it = lower_bound(S,S+3*n,r+S[i]) ;
        int id = it - S ;
        int nex = id % n ;
        A[i] = nex ;
        T[i] = s * n + id - i ;
    }
    Doubling d(A,T) ;
    d.build() ;
    rep(i,q){
        ll k ;
        cin >> k ;
        int v = d.get_index(0,k-1) ;
        cout << d.get_sum(v,1) << endl ;
    }
}