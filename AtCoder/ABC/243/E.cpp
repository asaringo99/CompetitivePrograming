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

int n , m ;
TP e[101010] ;
ll d[303][303] ;
bool use[303][303] ;

int f(){
    int res = 0 ;
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(i != k && j != k && use[i][j] && use[j][i] && d[i][k] + d[k][j] <= d[i][j]) {
                    res++ ;
                    use[i][j] = false ;
                    use[j][i] = false ;
                    chmin(d[i][j],d[i][k]+d[k][j]) ;
                }
                else{
                    chmin(d[i][j],d[i][k]+d[k][j]) ;
                }
            }
        }
    }
    return res ;
}

int main(){
    cin >> n >> m ;
    rep(i,n) rep(j,n){
        if(i != j) d[i][j] = 1e14 ;
    }
    rep(i,m){
        ll a , b , c ;
        cin >> a >> b >> c ;
        a-- ; b-- ;
        d[a][b] = c ;
        d[b][a] = c ;
        use[a][b] = true ;
        use[b][a] = true ;
    }
    int res = f() ;
    cout << res << endl ;
}