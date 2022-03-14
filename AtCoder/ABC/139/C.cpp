#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int K[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> K[i] ;
    int res = 0 , count = 0 ;
    rep(i,n-1){
        if(K[i] >= K[i+1]) count++ ;
        else count = 0 ;
        res = max(res,count) ;
    }
    cout << res << endl ;
}