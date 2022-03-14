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

int m , k ;

int main(){
    cin >> m >> k ;
    if(pow(2,m) <= k){
        cout << -1 << endl ;
        return 0 ;
    }
    if(m == 0 && k == 0){
        cout << 0 << " " << 0 << endl ;
        return 0 ;
    }
    if(m == 1){
        if(k == 0) cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl ;
        else cout << -1 << endl ;
        return 0 ;
    }
    vector<int> sub ;
    for(int i = 0 ; i < 1 << m ; i++){
        if(i == k) continue ;
        sub.push_back(i) ;
    }
    for(int i = sub.size() / 2 - 1 ; i >= 0 ; i--) cout << sub[i] << " " ;
    cout << k << " " ;
    for(int i = 0 ; i < sub.size() ; i++) cout << sub[i] << " " ;
    cout << k << " " ;
    for(int i = sub.size() - 1 ; i >= sub.size() / 2 ; i--) cout << sub[i] << " " ;
    cout << endl ;
}