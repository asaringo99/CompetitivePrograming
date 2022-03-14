#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , x ;
int A[110] ;
bool dp[10100] ;

int main(){
    cin >> x >> n ;
    rep(i,n) cin >> A[i] ;
    dp[x] = 0 ;
    for(int i = x - 1 ; i >= 0 ; i--){
        bool res = false ;
        rep(j,n) {
            if(i + A[j] > x) continue ;
            if(!dp[i+A[j]]) res = true ;
        }
        dp[i] = res ;
    }
    if(dp[0]) cout << "Alice" << endl ;
    else cout << "Bob" << endl ;
}