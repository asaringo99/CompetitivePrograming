#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(a,b,n) for(int a = b ; a < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , d ;

int main(){
    cin >> n >> d ;
    int X[n][d] ;
    rep(i,n) rep(j,d) cin >> X[i][j] ;
    int res = 0 ;
    rep(i,n){
        for(int j = i + 1 ; j < n ; j++){
            int sum = 0 ;
            rep(k,d){
                sum += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]) ;
            }
            int val = 1 ;
            while(val * val < sum) val++ ;
            if(val * val == sum) res++ ;
        }
    }
    cout << res << endl ;
}