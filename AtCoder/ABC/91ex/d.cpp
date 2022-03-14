#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] , B[202020] ;
ll AX[101] , BX[101] , X[101] ;

int main(){
    cin >> n ;
    ll XOR = 0 ;
    rep(i,n){
        ll a ;
        cin >> a ;
        A[i] = a ;
        XOR ^= a ;
        rep(j,30) if(a >> j & 1) AX[j]++ ;
    }
    rep(i,n){
        ll a ;
        cin >> a ;
        B[i] = a ;
        XOR ^= a ;
        rep(j,30) if(a >> j & 1) BX[j]++ ;
    }
    rep(i,n){
        rep(j,30){
            if(A[i] >> j & 1 && BX[j] & 1) XOR ^= (1 << (j + 1)) ;
        }
    }
    cout << XOR << endl ;
}