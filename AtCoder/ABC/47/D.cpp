#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , t ;
int A[101010] ;

int main(){
    cin >> n >> t ;
    rep(i,n) cin >> A[i] ;
    int maxval = -1 , count = 0 , maxmag = -1 ;
    for(int i = n - 1 ; i >= 1 ; i--){
        maxval = max(maxval,A[i]) ;
        if(maxval - A[i-1] == maxmag) count++ ;
        if(maxval - A[i-1] > maxmag){
            count = 1 ;
            maxmag = maxval - A[i-1] ;
        }
    }
    cout << count << endl ;
}