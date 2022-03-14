#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    ll d1 = -1 , d2 = -1 ;
    int node = -1 ;
    rrep(i,2,n+1){
        ll dist ;
        cout << "? " << 1 << " " << i << endl;
        cin >> dist;
        if(d1 < dist){
            d1 = dist ;
            node = i ;
        }
    }
    rrep(i,1,n+1){
        if(i == node) continue ;
        ll dist ;
        cout << "? " << node << " " << i << endl;
        cin >> dist;
        if(d2 < dist){
            d2 = dist ;
        }
    }
    cout << "! " << d2 << endl ;
}