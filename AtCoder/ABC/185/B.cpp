#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n , m , t ;

int main(){
    cin >> n >> m >> t ;
    int st = 0 , battery = n ;
    bool ok = true ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        battery = max(0,battery-(a-st)) ;
        if(battery == 0) ok = false ;
        battery = min(n,battery+b-a) ;
        st = b ;
    }
    battery = max(0,battery-(t-st)) ;
    if(battery == 0) ok = false ;
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}