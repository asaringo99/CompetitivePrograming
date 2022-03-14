#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    int p[n] ;
    for(int i = 0 ; i < n ; i++) cin >> p[i] ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(p[i] - 1 == i){
            int u = p[i] ;
            p[i] = p[i+1] ;
            p[i+1] = u ;
            res++ ;
        }
    }
    cout << res << endl ;
}