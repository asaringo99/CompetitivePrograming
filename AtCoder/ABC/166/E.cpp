#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;
ll A[200007] ;
map<ll,int> rem1 ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rep(i,n){
        res += rem1[i - A[i]] ;
        rem1[A[i] + i]++ ;
    }
    cout << res << endl ;
}