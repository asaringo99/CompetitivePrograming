#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int P[30] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> P[i] ;
    int sum = 0 ;
    rrep(i,1,n-1){
        if(min(P[i-1],P[i+1]) < P[i] && P[i] < max(P[i-1],P[i+1])) sum++ ;
    }
    cout << sum << endl ;
}