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

ll q , l ;
vector<P> vec = {P(0,0)} ;

int main(){
    cin >> q >> l ;
    ll num = 0 ;
    rep(i,q){
        string S ;
        cin >> S ;
        if(S == "Push"){
            ll n, m ;
            cin >> n >> m ;
            num += n ;
            if(num > l){
                cout << "FULL" << endl ;
                return 0 ;
            }
            vec.push_back(P(num,m)) ;
        }
        if(S == "Pop"){
            ll n ;
            cin >> n ;
            num -= n ;
            if(num < 0){
                cout << "EMPTY" << endl ;
                return 0 ;
            }
            ll val = -1 ;
            while(true){
                ll k = vec.size() - 1 ;
                ll v = vec[k].first ;
                if(k == 0 && num == 0) break ;
                if(v < num) {
                    vec.push_back(P(num,val)) ;
                    break ;
                }
                val = vec[k].second ;
                vec.pop_back() ;
            }
        }
        if(S == "Top"){
            if(num == 0){
                cout << "EMPTY" << endl ;
                return 0 ;
            }
            auto it = lower_bound(vec.begin(),vec.end(),P(num,-1e8)) ;
            cout << (*it).second << endl ;
        }
        if(S == "Size"){
            cout << num << endl ;
        }
    }
    cout << "SAFE" << endl ;
}