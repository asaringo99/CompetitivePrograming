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

string S ;
int n , k ;
vector<int> vec ;

int main(){
    fast_input_output
    cin >> n >> k >> S ;
    for(ll i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            vec.push_back(i) ;
            if(i * i != n) vec.push_back(n / i) ;
        }
    }
    sort(vec.begin(),vec.end()) ;
    int m = vec.size() ;
    ll res = 1e9 ;
    rep(i,m){
        ll len = vec[i] ;
        rep(j,n) {
            int count = 0 ;
            int p = k ;
            while(count < n){
                int tt = count % len ;
                if(S[(j+count)%n] != S[(j+tt)%n]) p-- ;
                count++ ;
            }
            if(p >= 0) chmin(res,len) ;
        }
    }
    cout << res << endl ;
}