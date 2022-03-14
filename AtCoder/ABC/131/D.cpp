#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
P A[202020] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i].second >> A[i].first ;
    sort(A,A+n) ;
    ll tim = 0 ;
    bool ok = true ; 
    rep(i,n){
        tim += A[i].second ;
        if(tim > A[i].first) ok = false ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}