#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , k , q ;
ll A[101010] ;

int main(){
    cin >> n >> k >> q ;
    rep(i,n) A[i] = k - q ;
    rep(i,q){
        ll a ;
        cin >> a ;
        a-- ;
        A[a]++ ;
    }
    rep(i,n){
        if(A[i] <= 0) cout << "No" << endl ;
        else cout << "Yes" << endl ;
    }
}