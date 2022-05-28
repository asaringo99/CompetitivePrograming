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

int n , m ;
ll dp[101][101][4][4][4][4][4][4][4] ;

void solve(int a , int b , int c , int x , int y , int z , int k){
    
}

int main(){
    fast_input_output
    cin >> m >> n ;
    dp[0][0][0][0][0][0][0][0][1] = 1 ;
    dp[0][0][0][0][0][0][0][0][2] = 1 ;
    dp[0][0][0][0][0][0][0][0][3] = 1 ;
    rep(i,m) rep(j,n){
        rep(a,4){
            if(i > 5 && a == 0) continue;
            rep(b,4){
                if(i > 5 && b == 0) continue;
                rep(c,4){
                    if(i > 5 && c == 0) continue;
                    rep(x,4){
                        if(j > 5 && x == 0) continue;
                        rep(y,4){
                            if(j > 5 && y == 0) continue;
                            rep(z,4){
                                if(j > 5 && z == 0) continue;
                                rep(k,4){
                                    if(k == 0) continue ;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}