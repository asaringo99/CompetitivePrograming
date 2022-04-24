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
ll B[101] ;

int main(){
    cin >> n ;
    rep(i,n-1) cin >> B[i] ;
    ll res = 0 ;
    rep(i,n-1){
        if(i == 0) res += B[i] ;
        else res += min(B[i],B[i-1]) ;
        if(i == n - 2) res += B[i] ;
    }
    cout << res << endl ;
}

