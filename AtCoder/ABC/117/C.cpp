#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

int main(){
    cin >> n >> m ;
    int X[m] ;
    for(int i = 0 ; i < m ; i++) cin >> X[i] ;
    sort(X,X+m) ;
    int S[m - 1] ;
    for(int i = 0 ; i < m - 1 ; i++){
        S[i] = X[i + 1] - X[i] ;
    }
    sort(S,S+m-1,greater<int>()) ;
    ll res = 0 ;
    for(int i = n - 1 ; i < m - 1 ; i++){
        res += S[i] ;
    }
    cout << res << endl ;
}