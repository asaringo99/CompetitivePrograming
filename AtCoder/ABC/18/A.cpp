#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

P A[3] ;
int res[3] ;

int main(){
    rep(i,3){
        int a ;
        cin >> a ;
        A[i].first = a ;
        A[i].second = i ;
    }
    sort(A,A+3) ;
    rep(i,3){
        res[A[i].second] = 3 - i ;
    }
    rep(i,3) cout << res[i] << endl ;
}