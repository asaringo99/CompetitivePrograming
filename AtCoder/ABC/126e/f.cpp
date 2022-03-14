#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int m , k ;
ll A[1010101] ;

int main(){
    cin >> m >> k ;
    if((1 << m) <= k || (m == 1 && k == 1)){
        cout << -1 << endl ;
        return 0 ;
    }
    if(m == 1 && k == 0){
        cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl ;
        return 0 ;
    }
    rep(i,1<<m){
        if(i == k) continue ;
        cout << i << " " ;
    }
    cout << k << " " ;
    rep(i,1<<m){
        if((1 << m) - 1 - i == k) continue ;
        cout << (1 << m) - 1 - i << " " ;
    }
    cout << k << endl ;
}