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

int n , m , c ;

int main(){
    cin >> n >> m >> c ;
    int B[m] ;
    for(int i = 0 ; i < m ; i++) cin >> B[i] ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        int sum = 0 ;
        for(int j = 0 ; j < m ; j++){
            int a ;
            cin >> a ;
            sum += B[j] * a ;
        }
        if(sum + c > 0) res++ ;
    }
    cout << res << endl ;
}