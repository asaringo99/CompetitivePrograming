#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int  main(){
    cin >> t ;
    rep(i,t){
        ll n ;
        cin >> n ;
        if(n % 6 == 0) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}