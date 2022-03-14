#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll D , G ;

int main(){
    cin >> D >> G ;
    ll p[D] , c[D] ;
    for(int i = 0 ; i < D ; i++) cin >> p[i] >> c[i] ;
    ll res = LLONG_MAX ;
    for(int i = 0 ; i < (1 << D) ; i++){
        bool used[D] ;
        ll point = 0 , count = 0 ;
        memset(used,0,sizeof(used)) ;
        for(int j = 0 ; j < D ; j++){
            if(i >> j & 1){
                used[j] = true ;
                point += p[j] * (j + 1) * 100 + c[j] ;
                count += p[j] ;
            }
        }
        if(point >= G) {
            res = min(res,count) ;
            continue ;
        }
        for(int j = D - 1 ; j >= 0 ; j--){
            if(used[j]) continue ;
            int pls = (G - point) % ((j + 1) * 100) == 0 ? (G - point) / ((j + 1) * 100) : (G - point) / ((j + 1) * 100) + 1 ;
            if(pls < p[j]) res = min(res,count+pls) ;
            break ;
        }
    }
    cout << res << endl ;
}