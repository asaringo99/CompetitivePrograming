#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
bool d[10][10] ;
int dp[1 << 10][10] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        d[a][b] = true ;
        d[b][a] = true ;
    }
    dp[1][0] = 1 ;
    for(int S = 1 ; S < 1 << n ; S++){
        for(int i = 0 ; i < n ; i++){
            if(!(S >> i & 1)) continue ;
            for(int j = 0 ; j < n ; j++){
                if(S >> j & 1) continue ;
                if(!d[i][j]) continue ;
                dp[S | (1 << j)][j] += dp[S][i] ;
            }
        }
    }
    int res = 0 ;
    for(int i = 1 ; i < n ; i++) res += dp[(1 << n) - 1][i] ;
    cout << res << endl ;
}