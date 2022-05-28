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

int n , x ;
vector<int> vec[10], res ;
int sum[10] ;

int main(){
    fast_input_output
    cin >> n >> x ;
    if(n == 2){
        cout << x << " " << (3 ^ x) << endl ;
        return 0 ;
    }
    int s ;

    s = x ;
    int count = 0 ;
    while(true){
        vec[1].push_back(s) ;
        count++ ;
        if(count % 2 == 0) s += count ;
        else s -= count ;
        if(s <= 0 || s > n) break ;
    }

    s = x ;
    while(true){
        vec[2].push_back(s) ;
        count++ ;
        if(count % 2 == 0) s -= count ;
        else s += count ;
        if(s <= 0 || s > n) break ;
    }

    int i ;
    i = 0 ;
    count = 0 ;
    s = x ;
    vec[3].push_back(s) ;
    s = n / 2 ;
    if(s != x && s != 0 && s != n) while(true){
        vec[3].push_back(s) ;
        count++ ;
        if(i % 2 == 0) {
            if(x == s - count) count++ ;
            s -= count ;
        }
        else {
            if(x == s + count) count++ ;
            s += count ;
        }
        if(s <= 0 || s > n) break ;
        i++ ;
    }

    count = 0 ;
    i = 0 ;
    s = x ;
    vec[4].push_back(s) ;
    s = n / 2 ;
    if(s != x && s != 0 && s != n) while(true){
        vec[4].push_back(s) ;
        count++ ;
        if(i % 2 != 0) {
            if(x == s - count) count++ ;
            s -= count ;
        }
        else {
            if(x == s + count) count++ ;
            s += count ;
        }
        if(s <= 0 || s > n) break ;
        i++ ;
    }

    count = 0 ;
    i = 0 ;
    s = x ;
    vec[5].push_back(s) ;
    s = n / 2 + 1 ;
    if(s != x && s != 0 && s != n) while(true){
        vec[5].push_back(s) ;
        count++ ;
        if(i % 2 == 0) {
            if(x == s - count) count++ ;
            s -= count ;
        }
        else {
            if(x == s + count) count++ ;
            s += count ;
        }
        if(s <= 0 || s > n) break ;
        i++ ;
    }

    count = 0 ;
    i = 0 ;
    s = x ;
    vec[6].push_back(s) ;
    s = n / 2 + 1 ;
    if(s != x && s != 0 && s != n) while(true){
        vec[6].push_back(s) ;
        count++ ;
        if(i % 2 != 0) {
            if(x == s - count) count++ ;
            s -= count ;
        }
        else {
            if(x == s + count) count++ ;
            s += count ;
        }
        if(s <= 0 || s > n) break ;
        i++ ;
    }

    count = 0 ;
    i = 0 ;
    s = x ;
    vec[7].push_back(s) ;
    s = n / 2 - 1 ;
    if(s != x && s != 0 && s != n) while(true){
        vec[7].push_back(s) ;
        count++ ;
        if(i % 2 == 0) {
            if(x == s - count) count++ ;
            s -= count ;
        }
        else {
            if(x == s + count) count++ ;
            s += count ;
        }
        if(s <= 0 || s > n) break ;
        i++ ;
    }

    count = 0 ;
    i = 0 ;
    s = x ;
    vec[8].push_back(s) ;
    s = n / 2 - 1 ;
    if(s != x && s != 0 && s != n) while(true){
        vec[8].push_back(s) ;
        count++ ;
        if(i % 2 != 0) {
            if(x == s - count) count++ ;
            s -= count ;
        }
        else {
            if(x == s + count) count++ ;
            s += count ;
        }
        if(s <= 0 || s > n) break ;
        i++ ;
    }

    int ans = 0  , id = -1;
    rrep(i,1,9){
        int f = 0 ;
        if(vec[i].size() != n) continue;
        rep(j,vec[i].size()-1){
            if(abs(vec[i][j+1] - vec[i][j]) > f) sum[i]++ ;
            else sum[i] = 0 ;
            f = abs(vec[i][j+1] - vec[i][j]) ;
            if(sum[i] > ans){
                ans = sum[i] ;
                id = i ;
            }
        }
    }
    for(int u : vec[id]) cout << u << " " ; cout << endl ;
}