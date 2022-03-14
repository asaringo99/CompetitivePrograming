#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , c ;
int T[101010][50] ;

int main(){
    cin >> n >> c ;
    rep(i,n){
        int s , t , k ;
        cin >> s >> t >> k ;
        k-- ;
        T[s][k]++ ;
        T[t][k]-- ;
    }
    int res = 0 , sum = 0 ;
    rep(i,101010){
        rep(j,c) if(T[i][j] > 0) sum++ ;
        res = max(res,sum) ;
        rep(j,c) if(T[i][j] < 0) sum-- ;
    }
    cout << res << endl ;
}