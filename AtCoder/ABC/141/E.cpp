#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S ;
ll dp[5050][5050] ;

int main(){
    cin >> n >> S ;
    ll res  = 0 ;
    rep(i,n) rep(j,n){
        if(S[i] == S[j] && abs(j - i) > dp[i][j]){
            dp[i+1][j+1] = dp[i][j] + 1 ;
            res = max(res,dp[i+1][j+1]) ;
        }
    }
    cout << res << endl ;
}