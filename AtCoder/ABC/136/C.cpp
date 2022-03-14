#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll H[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> H[i] ;
    rrep(i,1,n){
        if(H[i-1] > H[i]){
            cout << "No" << endl ;
            return 0 ;
        }
        else if(H[i-1] != H[i]){
            H[i]-- ;
        }
    }
    cout << "Yes" << endl ;
}