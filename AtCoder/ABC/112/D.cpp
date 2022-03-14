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
    vector<int> prm ;
    for(int i = 1 ; i * i <= m ; i++){
        if(m % i == 0){
            prm.push_back(i) ;
            if(i * i != m) prm.push_back(m/i) ;
        }
    }
    int k = m / n ;
    int res = 0 ;
    for(int u : prm){
        if(u <= k) res = max(res,u) ;
    }
    cout << res << endl ;
}