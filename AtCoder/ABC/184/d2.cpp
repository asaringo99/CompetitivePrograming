#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
double dp[301][301][301] ;

int main(){
    cin >> n ;
    int X = 0 , Y = 0 , Z = 0 ;
    rep(i,n){
        int a ;
        cin >> a ;
        if(a == 1) X++
        if(a == 2) Y++
        if(a == 3) Z++
    }
    dp[X][Y][Z] = 0 ;
    for(int i = X ; i >= 0 ; i--){
        for(int j = Y ; j >= 0 ; j--){
            for(int k = Z ; k >= 0 ; k--){
                
            }
        }
    }
}