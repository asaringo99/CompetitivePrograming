#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , a ;
string k ;
int X[101010] ;
bool used[101010] ;

// string g(string k , ll x){
//     string y = "" ;
//     int m = k.size() ;
//     bool ok ;
//     for(int)
// }

int f(string k , ll x){
    int i = 0 ; 
    ll res = 0 ;
    while(true){
        int d = 0 ;
        while(i+d < k.size() && res < x){
            cout << res << endl ;
            res = 10 * res + (k[i+d] - '0') ;
            d++ ;
        }
        if(i + d == k.size()) break ;
        res %= x ;
        i = d++ ;
    }
    return res ;
}

int main(){
    cout << f("11",3) << endl ;
    cin >> n >> a >> k ;
    a-- ;
    rep(i,n){
        int x ;
        cin >> x ;
        x-- ;
        X[i] = x ;
    }
    if(k.size() <= 8){

    }
    int cnt = 0 ;
    used[a] = true ;
    while(!used[a]){
        a = X[a] ;
        cnt++ ;
        used[a] = true ;
    }
    int sum = 0 ;
    int v = a ;
    while(X[v] != a){
        v = X[v] ;
        sum++ ;
    }
    sum++ ;

}