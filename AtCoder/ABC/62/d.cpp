#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
priority_queue<ll,vector<ll>,greater<ll>> lef ;
priority_queue<ll> rig ;

ll A[303030] ;
ll L[101010] , R[101010] ;

int main(){
    cin >> n ;
    rep(i,3*n) cin >> A[i] ;
    ll ls = 0 , rs = 0 ;
    rep(i,n) lef.push(A[i]) , ls += A[i] ;
    rep(i,n) rig.push(A[3*n-1-i]) , rs += A[3 * n - 1 - i] ;
    L[0] = ls ;
    R[0] = rs ;
    rep(i,n){
        ll top = lef.top() ;
        if(top < A[n + i]){
            lef.pop() ;
            lef.push(A[n + i]) ;
            ls -= top ;
            ls += A[n + i] ;
        }
        L[i+1] = ls ;
    }
    rep(i,n){
        ll top = rig.top() ;
        if(top > A[2 * n - 1 - i]){
            rig.pop() ;
            rig.push(A[2 * n - 1 - i]) ;
            rs -= top ;
            rs += A[2 * n - 1 - i] ;
        }
        R[i+1] = rs ;
    }
    ll res = -1e18 ;
    rep(i,n+1){
        res = max(res,L[i] - R[n-i]) ;
    }
    cout << res << endl ;
}