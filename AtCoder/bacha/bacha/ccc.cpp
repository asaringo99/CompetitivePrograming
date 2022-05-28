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

int n , L ;
int X[101010] ;
char D[101010] ;

int main(){
    fast_input_output
    cin >> n >> L ;
    rrep(i,1,n+1) cin >> X[i] >> D[i] ;
    X[0] = 0 , X[n + 1] = L + 1 ;
    int r = 1 ;
    vector<vector<int>> vec ;
    vector<int> v ;
    while(r < n + 1){
        while(r < n + 1){
            if(D[r] == 'R') break ;
            v.push_back(r) ;
            r++ ;
        }
        vec.push_back(v) ;
        v = {} ;
        while(r < n + 1){
            if(D[r] == 'L') break ;
            v.push_back(r) ;
            r++ ;
        }
    }
    vec.push_back(v) ;
    ll res = 0 ;
    for(vector<int> vc : vec){
        if(vc.empty()) continue;
        int i = vc[0] ;
        int m = vc[vc.size()-1] ;
        ll lsum = 0 , rsum = 0 , lef = 0 , rig = 0 ;
        int j = i ;
        ll cnt = 0 ;
        while(j < m + 1) {
            if(D[j] == 'L') break ;
            j++ ;
            cnt++ ;
        }
        cnt = max(cnt,(int)vc.size()-cnt) ;
        int s = j + 1 ;
        while(s < m + 1){
            lef += X[s] - X[s-1] - 1 ;
            lsum += lef ;
            s++ ;
        }
        int t = j - 2 ;
        while(t >= i){
            rig += X[t+1] - X[t] - 1 ;
            rsum += rig ;
            t-- ;
        }
        res += lsum + rsum + cnt * (X[j] - X[j-1] - 1) ;
    }
    cout << res << endl ;
}