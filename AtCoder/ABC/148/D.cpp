#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[200007] ;

int main(){
    cin >> n ;
    int check = 0 ;
    rep(i,n) {
        int a ;
        cin >> a ;
        if(a - 1 == check) check++ ;
    }
    if(check == 0) cout << -1 << endl ;
    else cout << n - check << endl ;
}