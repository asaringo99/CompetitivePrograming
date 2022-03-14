#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n ;

int main(){
    cin >> n ;
    map<int,int> good ;
    int A[n] ;
    rep(i,n) {
        int a ;
        cin >> a ;
        A[i] = a ;
        good[a]++ ;
    }
    ll res = 0 ;
    rep(i,n) {
        ll tmp = good[A[i]] > A[i] ? good[A[i]] - A[i] : good[A[i]] % A[i] ;
        res += tmp ;
        good[A[i]] = 0 ;
    }
    cout << res << endl ;
}