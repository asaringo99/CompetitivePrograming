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
int A[100] , B[100] , C[100] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i+1] ;
    rep(i,n) cin >> B[i+1] ;
    rep(i,n-1) cin >> C[i+1] ;
    int res = 0 ;
    rrep(i,1,n+1){
        res += B[A[i]] ;
        if(A[i+1] == A[i] + 1) res += C[A[i]] ;
    }
    cout << res << endl ;
}