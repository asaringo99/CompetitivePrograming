#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , s , t ;
TP X[50] ;

int main(){
    cin >> n >> s >> t ;
    rep(i,n){
        int a , b , c ;
        cin >> a >> b >> c ;
        X[i] = {a,b,c} ;
    }
    int x = n / 2 , y = n - x ;

    int res = 1e9 ;
    vector<P> vec ;
    vec.push_back(P(0,0)) ;
    rrep(i,1,1<<x){
        int suma = 0 , sumb = 0 , sumc = 0 ;
        rep(j,x) if(i >> j & 1){
            int a , b , c ;
            tie(a,b,c) = X[j] ;
            suma += a ;
            sumb += b ;
            sumc += c ;
        }
        suma *= t ;
        sumb *= s ;
        if(suma == sumb) res = min(res,sumc) ;
        vec.push_back(P(suma-sumb,sumc)) ;
    }
    sort(vec.begin(),vec.end()) ;
    rrep(i,1,1<<y){
        int suma = 0 , sumb = 0 , sumc = 0 ;
        rep(j,y) if(i >> j & 1){
            int a , b , c ;
            tie(a,b,c) = X[x+j] ;
            suma += a ;
            sumb += b ;
            sumc += c ;
        }
        suma *= t ;
        sumb *= s ;
        auto it = lower_bound(vec.begin(),vec.end(),P(sumb-suma,-1)) ;
        if(it->first == sumb-suma){
            res = min(res,sumc+it->second) ;
        }
    }
    if(res == 1e9) res = -1 ;
    cout << res << endl ;
}