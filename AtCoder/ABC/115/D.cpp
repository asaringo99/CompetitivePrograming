#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n , x ;

int main(){
    cin >> n >> x ;
    x-- ;
    ll ban = 5 , pat = 3 , level = n ;
    for(int i = 1 ; i < n ; i++) ban = (ban * 2) + 3 ;
    for(int i = 1 ; i < n ; i++) pat = (pat * 2) + 1 ;
    ll res = 0 , lef = 0 , rig = ban ;
    while(level > 0){
        ll m = (lef + rig) / 2 ;
        if(level == 1){
            int pls = x - lef ;
            if(pls == 4) pls-- ;
            res += pls ;
            break ;
        }
        if(m == x){
            res += (pat - 1) / 2 + 1 ;
            break ;
        }
        if(m < x){
            res += (pat - 1) / 2 + 1 ;
            pat = (pat - 1) / 2 ;
            lef = m + 1 ;
            rig-- ;
            if(lef == x) break ;
            if(rig == x){
                res += pat ;
                break ;
            }
        }
        if(m > x){
            pat = (pat - 1) / 2 ;
            lef++ ;
            rig = m - 1 ;
            if(lef == x) break ;
            if(rig == x){
                res += pat ;
                break ;
            }
        }
        level-- ;
    }
    cout << res << endl ;
}