#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int p[55] , q[55] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] , q[i] = i + 1 ;
    int sum = 0 ;
    rrep(i,0,n) if(p[i] != q[i]) sum++ ;
    if(sum > 2) cout << "NO" << endl ;
    else cout << "YES" << endl ;
}