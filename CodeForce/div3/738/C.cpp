#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int main(){
    cin >> t ;
    rep(z,t){
        int n ;
        int A[10100] ;
        cin >> n ;
        rep(i,n) cin >> A[i] ;
        bool ok = true ;
        rep(i,n) if(A[i] == 0) ok = false ;
        if(ok) {
            cout << -1 << endl ;
            continue ;
        }
        if(A[n-1] == 0){
            rep(i,n) cout << i + 1 << " " ;
            cout << n + 1 << endl ;
        }
        else{
            bool gd = true ;
            rep(i,n-1){
                cout << i + 1 << " " ;
                if(gd && A[i] == 0 && A[i + 1] == 1) {
                    cout << n + 1 << " " ;
                    gd = false ;
                }
            }
            cout << n << endl ;
        }
    }
}