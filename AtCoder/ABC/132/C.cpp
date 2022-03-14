#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int D[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> D[i] ;
    sort(D,D+n) ;
    cout << D[n/2] - D[n/2-1] << endl ;
}