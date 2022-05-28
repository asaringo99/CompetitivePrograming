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

int H , W ;
ll C[101][101] , S[101][101] ;
ll D[101][101] , T[101][101] ;

int main(){
    fast_input_output
    cin >> H >> W ;
    rep(i,H) rep(j,W) {
        int c ;
        cin >> c ;
        if((i + j) % 2 == 0) C[i][j] = c ;
        if((i + j) % 2 != 0) D[i][j] = c ;
    }
    rep(i,H) rep(j,W){
        S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + C[i][j] ;
        T[i+1][j+1] = T[i+1][j] + T[i][j+1] - T[i][j] + D[i][j] ;
    }
    int res = 0 ;
    rep(i,H) rep(j,W) rrep(x,i,H) rrep(y,j,W) {
        if(S[x+1][y+1] - S[x+1][j] - S[i][y+1] + S[i][j] == T[x+1][y+1] - T[x+1][j] - T[i][y+1] + T[i][j]) {
            chmax(res,(x-i+1)*(y-j+1)) ;
        }
    }
    cout << res << endl ;
}