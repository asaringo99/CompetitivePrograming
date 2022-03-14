#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int r , c , k , n ;

ll col[101010] , col2[101010] , row[101010] ;
vector<int> candy[101010] ;

int main(){
    cin >> r >> c >> k >> n ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        candy[a].push_back(b) ;
        row[a]++ ;
        col[b]++ ;
        col2[b]++ ;
    }
    ll res = 0 ;
    sort(col,col+c) ;
    rep(i,r){
        res += upper_bound(col,col+c,k-row[i]) - lower_bound(col,col+c,k-row[i]) ;
        for(int u : candy[i]){
            if(row[i] + col2[u] == k) res-- ;
            if(row[i] + col2[u] == k + 1) res++ ;
        }
    }
    cout << res << endl ;
}