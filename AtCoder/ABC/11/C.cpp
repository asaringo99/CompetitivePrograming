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

int n , a , b , c ;

bool cal(int n , int val){
    if(n - val == a || n - val == b || n - val == c) return false ;
    return true ;
}

int main(){
    cin >> n >> a >> b >> c ;
    int count = 0 ;
    bool ok = true ;
    while(n > 0){
        if(n == a || n == b || n == c){
            ok = false ;
            break ;
        }
        if(cal(n,3)){
            n -= 3 ;
            count++ ;
            continue ;
        }
        if(cal(n,2)){
            n -= 2 ;
            count++ ;
            continue ;
        }
        if(cal(n,1)){
            n -= 1 ;
            count++ ;
            continue ;
        }
        ok = false ;
        break ;
    }
    if(!ok){
        cout << "NO" << endl ;
        return 0 ;
    }
    if(count > 100) {
        cout << "NO" << endl ;
        return 0 ;
    }
    cout << "YES" << endl ;
}