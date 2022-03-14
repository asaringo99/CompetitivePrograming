#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;

ll dp[(1 << 18) + 7] ;
int bit[20] ;
vector<P> query[20] ;

int main(){
    cin >> n >> m ;
    rep(i,m){
        int x , y , z ;
        cin >> x >> y >> z ;
        query[x].push_back(P(y,z)) ;
    }
    rep(i,n-1) bit[i+1] = bit[i] << 1 | 1 ;
    dp[0] = 1 ;
    for(int i = 0 ; i < (1 << n) ; i++){
        int count = 0 ;
        for(int j = 0 ; j < n ; j++) if(i >> j & 1) count++ ;
        for(P p : query[count]){
            int y = p.first , z = p.second ;
            int S = i & bit[y] ;
            int tmp = 0 ;
            for(int k = 0 ; k < n ; k++) if(S >> k & 1) tmp++ ;
            if(tmp > z) dp[i] = 0 ;
        }
        for(int j = 0 ; j < n ; j++){
            if(~i & 1 << j) dp[i | 1 << j] += dp[i] ;
        }
    }
    cout << dp[(1 << n) - 1] << endl ;
}